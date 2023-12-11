#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
string p_id;   
int start_time, burst_time, wait = 0, turn_around = 0, run_time = 0;
 	Process(string p_id, int start_time, int burst_time)
        		: p_id(p_id), start_time(start_time), burst_time(burst_time) {}
};

bool strt_time_cmp(Process p1, Process p2) {return p1.start_time < p2.start_time;}

void RRScheduling(vector<Process> table, int time_quantum) {

    cout << "Time Quantum:" << time_quantum << "\n";
    
    double avg_wait = 0, avg_turn_around = 0;
    int completion_time = 0;
    vector<Process> res_table;    
    vector<Process> q;
    bool notEmpty = false;
    while (table.size() > 0 || q.size() > 0) {
        int index = 0;
        if (q.size() != 0) notEmpty = true;
        int j = 0;
        while (j < table.size()) {
            if (table[j++].start_time > completion_time) break;
            else {q.push_back(table[--j]); table.erase(table.begin());}
        }
        if (notEmpty) {
            q.push_back(q[0]);
            q.erase(q.begin());
        }
        if (q.size() == 0) continue;
        Process p = q[0];
        
        q[0].run_time += time_quantum;
        if (p.burst_time <= q[0].run_time) {
            p.wait = max(0,completion_time - p.start_time - p.burst_time + time_quantum);
            p.turn_around = p.wait + p.burst_time;
            
            avg_wait += p.wait;
            avg_turn_around +=  p.turn_around;
            q.erase(q.begin() + index);
            res_table.push_back(p);
        }
        
        completion_time += time_quantum;
    }

    cout << "Process\tStart Time\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (auto& i: res_table)
        cout << i.p_id << "\t\t" << i.start_time << "\t\t"
             << i.burst_time << "\t\t" 
             << i.wait << "\t\t" << i.turn_around << endl;

    int n = res_table.size();
    cout << "Average Waiting Time: " << avg_wait / n << "\n"
         << "Average Turnaround Time: " << avg_turn_around / n;
}

int main() {
    vector<Process> table = {{"P1", 0, 7}, {"P2", 2, 5}, {"P3", 4, 1}, 
      {"P4", 5, 4}, {"P5", 6, 2}, {"P6", 2, 3}};

    sort(table.begin(), table.end(), strt_time_cmp);

    RRScheduling(table,2);
    cout << "\n\n";

    RRScheduling(table,3);
    cout << "\n\n";
    RRScheduling(table,4);
    cout << "\n\n";

    RRScheduling(table,5);
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
string p_id;    
int start_time, burst_time, priority, wait = 0, turn_around = 0, run_time = 0;
 	Process(string p_id, int start_time, int burst_time, int priority)
        		: p_id(p_id), start_time(start_time), burst_time(burst_time), priority(priority) {}
};

bool strt_time_cmp(Process p1, Process p2) {
    if (p1.start_time == p2.start_time) 
return p1.priority < p2.priority;
    return p1.start_time < p2.start_time;
}

void PriorityScheduling(vector<Process> table) {
    double avg_wait = 0, avg_turn_around = 0;
    int n = table.size(), completion_time = 0;
    vector<Process> res_table;
    
    
while (table.size() > 0) {
        Process p = table[0];
        int index = 0;
        for (int j = 0; j < table.size(); j++) {
            if (table[j].start_time > completion_time) break;
            else if (table[j].priority > p.priority) {
                        p = table[j];
                        index = j;
            }
        }
        
        table[index].run_time += 1;
        if (p.burst_time == table[index].run_time) {
            p.wait = max(0,completion_time - p.start_time - p.burst_time + 1);
            p.turn_around = p.wait + p.burst_time;
            
            avg_wait += p.wait;
            avg_turn_around +=  p.turn_around;
            table.erase(table.begin() + index);
            res_table.push_back(p);
        }
        completion_time += 1;
        
    }
    
    cout << "Process\tStart Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++)
        cout << res_table[i].p_id << "\t\t" << res_table[i].start_time << "\t\t"
                << res_table[i].burst_time << "\t\t" << res_table[i].priority << "\t\t" 
                << res_table[i].wait << "\t\t" << res_table[i].turn_around << endl;

    cout << "Average Waiting Time: " << avg_wait / n << "\n"
         << "Average Turnaround Time: " << avg_turn_around / n;
}

int main() 
{
    vector<Process> table = {{"P1", 0, 7, 3}, {"P2", 2, 5, 2}, {"P3", 4, 1, 1}, 
      {"P4", 5, 4, 4}, {"P5", 6, 2, 2}, {"P6", 2, 3, 1}};

    sort(table.begin(), table.end(), strt_time_cmp);
    PriorityScheduling(table);

    return 0;
}

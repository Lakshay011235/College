#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {string p_id;    int start_time, burst_time; };
bool strt_time_cmp(Process p1, Process p2) {
    if (p1.start_time == p2.start_time) return p1.burst_time < p2.burst_time;
    return p1.start_time < p2.start_time;
}

void SJFScheduling(vector<Process> table) {
    double avg_wait = 0, avg_turn_around = 0;
    int n = table.size(), completion_time = 0;
    vector<int> wait(n,0), turn_around(n,0);
    vector<Process> res_table;
    
    int i = 0;
    while (table.size() > 0) {
        Process p = table[0];
        int index = 0;
        for (int j = 0; j < table.size(); j++) {
            if (table[j].start_time > completion_time) break;
            else if (table[j].burst_time < p.burst_time) {
                        p = table[j];
                        index = j;
            }
        }
        wait[i] = completion_time - p.start_time;
        turn_around[i] = wait[i] + p.burst_time;
        
        avg_wait += wait[i];
        avg_turn_around +=  turn_around[i];
        
        completion_time += p.burst_time;
        table.erase(table.begin() + index);
        res_table.push_back(p);
        
        i++;
    }
    
    cout << "Process\tStart Time\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++)
        cout << res_table[i].p_id << "\t\t" << res_table[i].start_time << "\t\t"
             << res_table[i].burst_time << "\t\t" << wait[i] << "\t\t" << turn_around[i] << endl;

    cout << "Average Waiting Time: " << avg_wait / n << "\n"
         << "Average Turnaround Time: " << avg_turn_around / n;
}

int main() {
    vector<Process> table = {{"P1", 0, 7}, {"P2", 2, 5}, {"P3", 4, 1}, 
       {"P4", 5, 4}, {"P5", 6, 2}, {"P6", 2, 3}};
    sort(table.begin(), table.end(), strt_time_cmp);
    SJFScheduling(table);
    return 0;
}

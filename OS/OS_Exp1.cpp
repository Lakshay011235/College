#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {string p_id;    int arrival_time, burst_time; };
bool strt_time_cmp(Process p1, Process p2) {return p1.arrival_time < p2.arrival_time;}

void FCFSScheduling(vector<Process> table) {
    double avg_wait = 0, avg_turn_around = 0;
    int n = table.size(), completion_time = table[0].burst_time;
    vector<int> wait(n,0), turn_around(n,0);
    
    turn_around[0] = table[0].burst_time;
    
    for (int i = 1; i < n; i++) {
        Process p = table[i];
        wait[i] = completion_time - table[i].arrival_time;
        turn_around[i] = wait[i] + table[i].arrival_time;
        
        avg_wait += wait[i];
        avg_turn_around +=  turn_around[i];
        
        completion_time += table[i].burst_time;
    }
    
    cout << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++)
        cout << table[i].p_id << "\t\t" << table[i].arrival_time << "\t\t"
             << table[i].burst_time << "\t\t" << wait[i] << "\t\t" << turn_around[i] << endl;

    cout << "Average Waiting Time: " << avg_wait / n << "\n"
         << "Average Turnaround Time: " << avg_turn_around / n;
}

int main() {
    vector<Process> table = {{"P1", 0, 4},{"P2", 10, 33},{"P3", 4, 32},{"P4", 3, 5},{"P5", 3, 5}};
    
    sort(table.begin(), table.end(), strt_time_cmp);

    FCFSScheduling(table);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
};

bool isEarly(struct Process *p1, struct Process *p2)
{
    return (p1->burstTime <= p2->burstTime);
};#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {string p_id;    int start_time, burst_time, wait = 0, turn_around = 0,
run_time = 0;
 Process(string p_id, int start_time, int burst_time)
        : p_id(p_id), start_time(start_time), burst_time(burst_time) {}
};
bool strt_time_cmp(Process p1, Process p2) {
    if (p1.start_time == p2.start_time) return p1.burst_time < p2.burst_time;
    return p1.start_time < p2.start_time;
}
void SJFScheduling(vector<Process> table) {
    double avg_wait = 0, avg_turn_around = 0;
    int n = table.size(), completion_time = 0;
    vector<Process> res_table;
    
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
    
    cout << "Process\tStart Time\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++)
        cout << res_table[i].p_id << "\t\t" << res_table[i].start_time << "\t\t"
             << res_table[i].burst_time << "\t\t" 
             << res_table[i].wait << "\t\t" << res_table[i].turn_around << endl;

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


int main()
{
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d:\t", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for process %d:\t\t", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    // Sorting Processes by arrival time
    struct Process a;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (isEarly(&processes[j], &processes[i]))
            {
                a = processes[i];
                processes[i] = processes[j];
                processes[j] = a;
            }
        }
    }

    int waitingTime[n], turnaroundTime[n];

    waitingTime[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
    }
    for (int i = 0; i < n; i++)
    {
        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }

    printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, waitingTime[i], turnaroundTime[i]);
    }
    printf("\n");

    // Calculate average waiting time and average turnaround time
    float averageWaitingTime = 0, averageTurnaroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        averageWaitingTime += waitingTime[i];
        averageTurnaroundTime += turnaroundTime[i];
    }

    averageWaitingTime /= n;
    averageTurnaroundTime /= n;

    printf("Average Waiting Time: %.2f\n", averageWaitingTime);
    printf("Average Turnaround Time: %.2f\n", averageTurnaroundTime);
    printf("\nLakshay Sharma\t02396402721\n");
}
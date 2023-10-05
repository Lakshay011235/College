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
};

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
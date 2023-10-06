#include <stdio.h>

// Structure to represent a process
struct Process
{
    int id;          // Process ID
    int priority;    // Priority of the process (higher value means higher priority)
    int burstTime;   // Burst time or execution time of the process
    int arrivalTime; // Arrival time of the process
};

int main()
{
    // Number of processes
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
    }

    // Sort processes based on priority (and arrival time in case of tie)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].priority < processes[j + 1].priority ||
                (processes[j].priority == processes[j + 1].priority && processes[j].arrivalTime > processes[j + 1].arrivalTime))
            {
                // Swap processes if they are out of order
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
    // TODO: NEEEEEDDD TO ADD QUEUE OF THIS !!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    
    // Pre-emptive sorting
    for (int i = 0; i < n - 1; i++)
    {
        int remainingTime = processes[i].burstTime - (processes[i + 1].arrivalTime - processes[i].arrivalTime);
        if (processes[i + 1].burstTime < remainingTime)
        {
            struct Process temp = processes[i];
            processes[i] = processes[i + 1];
            processes[i + 1] = temp;
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

    // Display the execution order and turnaround time
    printf("\nProcess\t\tPriority\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t", processes[i].id, processes[i].priority, processes[i].arrivalTime);
        printf("%d\t\t%d\t\t%d\n", processes[i].burstTime, waitingTime[i], turnaroundTime[i]);
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
    return 0;
}
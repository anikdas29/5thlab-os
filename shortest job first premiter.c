//Program for Priority Scheduling sjf-p

#include <stdio.h>

int main() {
    int i, j, n, temp;
    int p[20], bt[20], pri[20], wt[20], tat[20];
    float awt = 0, atat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time and Priority of processes\n");
    for (i = 0; i < n; i++) {
        printf("   Process %d: ", i + 1);
        scanf("%d %d", &bt[i], &pri[i]);
        p[i] = i + 1;  // Assign process IDs
    }

    // Sort processes by priority (lower priority number means higher priority)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (pri[j] > pri[j + 1]) {
                // Swap process details
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pri[j];
                pri[j] = pri[j + 1];
                pri[j + 1] = temp;
            }
        }
    }

    wt[0] = 0;  // Waiting time for first process is 0
    tat[0] = bt[0];

    // Calculate waiting time and turnaround time for each process
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];
    }

    // Calculate average waiting time and turnaround time
    for (i = 0; i < n; i++) {
        awt += wt[i];
        atat += tat[i];
    }
    awt /= n;
    atat /= n;

    // Print the results in a formatted table
    printf("\n   ---------------------------------------------------------------------------------\n");
    printf("   | Process\t | Priority\t | Burst Time\t | Waiting Time\t | Turnaround Time  |\n");
    printf("   ---------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("   | P%d\t\t | %d\t\t | %d\t\t | %d\t\t | %d\t\t    |\n", p[i], pri[i], bt[i], wt[i], tat[i]);
    }
    printf("   ---------------------------------------------------------------------------------\n");
    printf("   | Average Waiting Time: %.2f \t\t\t\t\t\t    |\n", awt);
    printf("   | Average Turnaround Time: %.2f \t\t\t\t\t\t    |\n", atat);
    printf("   ---------------------------------------------------------------------------------\n");

    return 0;
}

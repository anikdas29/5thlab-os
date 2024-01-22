//Program for (FCFS) fast come first serve.

#include<stdio.h>
int main()
{
    int bt[20], wt[20], tat[20], i, n;
    float awt, atat;

    //Getting Input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter Burst Time for -\n");
    for(i=0; i<n; i++)
    {
        printf("   Process %d: ", i+1);
        scanf("%d", &bt[i]);
    }
    printf("\n");

    //Processing
    wt[0] = awt = 0;
    tat[0] = atat = bt[0];
    for(i=1; i<n; i++)
    {
        wt[i] = wt[i-1] +bt[i-1];
        tat[i] = tat[i-1] +bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    //Generated output
    printf("   ---------------------------------------------------------------");
    printf("\n   | PROCESS \t| BURST TIME \t| WAITING TIME \t| TURNAROUND TIME |\n");
    printf("   |--------------------------------------------------------------|");
    for(i=0; i<n; i++)
        printf("\n   | P%d \t| %d \t\t| %d \t\t| %d\t\t  |", i+1, bt[i], wt[i], tat[i]);

    printf("\n   |--------------------------------------------------------------|");
    printf("\n   | Average Waiting Time: %.3f\t\t\t\t  |", awt/n);
    printf("\n   | Average Turnaround Time: %.3f\t\t\t\t  |\n", atat/n);
    printf("   ---------------------------------------------------------------\n\n");

    return 0;
}

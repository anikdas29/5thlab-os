//Program for (SJF) Shortest Job First (non-preemptive)

#include<stdio.h>
int main()
{
    int p[20], bt[20], wt[20], tat[20], i, k, n, temp;
    float awt,atat;

    //Getting Input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter Burst Time for -\n");
    for(i=0; i<n; i++)
    {
        p[i]=i;
        printf("   Process %d: ", i+1);
        scanf("%d", &bt[i]);
    }
    printf("\n");

    //processing
    for(i=0; i<n; i++)
        for(k=i+1; k<n; k++)
            if(bt[i]>bt[k])
            {
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
            }
    wt[0] = awt = 0;
    tat[0] = atat = bt[0];
    for(i=1; i<n; i++)
    {
        wt[i] = wt[i-1] +bt[i-1];
        tat[i] = tat[i-1] +bt[i];
        awt += wt[i];
        atat += tat[i];
    }

    //Generated Output
    printf("   ---------------------------------------------------------------");
    printf("\n   | PROCESS \t| BURST TIME \t| WAITING TIME \t| TURNAROUND TIME |\n");
    printf("   |--------------------------------------------------------------|");
    for(i=0; i<n; i++)
        printf("\n   | P%d \t| %d \t\t| %d \t\t| %d\t\t  |", p[i]+1, bt[i], wt[i], tat[i]);

    printf("\n   |--------------------------------------------------------------|");
    printf("\n   | Average Waiting Time: %.3f\t\t\t\t  |", awt/n);
    printf("\n   | Average Turnaround Time: %.3f\t\t\t\t  |\n", atat/n);
    printf("   ---------------------------------------------------------------\n\n");

    return 0;
}

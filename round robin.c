//Program for Round Robin

#include<stdio.h>
int main()
{
    int i,j,n,bt[10],wt[10],tat[10],t,cpy_bt[10],max=0;
    float awt=0,atat=0,temp=0;

    //Getting Input
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\nEnter Burst Time for -\n");
    for(i=0; i<n; i++)
    {
        printf("   Process %d: ", i+1);
        scanf("%d",&bt[i]);
        cpy_bt[i]=bt[i];

        if(max<bt[i])
            max=bt[i];
    }
    printf("\nEnter the size of time slice: ");
    scanf("%d",&t);

    //Processing
    for(j=0; j<(max/t)+1; j++)
        for(i=0; i<n; i++)
            if(bt[i]!=0)
                if(bt[i]<=t)
                {
                    tat[i]=temp+bt[i];
                    temp=temp+bt[i];
                    bt[i]=0;
                }
                else
                {
                    bt[i]=bt[i]-t;
                    temp=temp+t;
                }
    for(i=0; i<n; i++)
    {
        wt[i]=tat[i]-cpy_bt[i];
        atat+=tat[i];
        awt+=wt[i];
    }

    //Generated output
    printf("   ---------------------------------------------------------------");
    printf("\n   | PROCESS \t| BURST TIME \t| WAITING TIME \t| TURNAROUND TIME |\n");
    printf("   |--------------------------------------------------------------|");
    for(i=0; i<n; i++)
        printf("\n   | P%d \t| %d \t\t| %d \t\t| %d\t\t  |", i+1, cpy_bt[i], wt[i], tat[i]);

    printf("\n   |--------------------------------------------------------------|");
    printf("\n   | Average Waiting Time: %.3f\t\t\t\t  |", awt/n);
    printf("\n   | Average Turnaround Time: %.3f\t\t\t\t  |\n", atat/n);
    printf("   ---------------------------------------------------------------\n\n");

    return 0;
}

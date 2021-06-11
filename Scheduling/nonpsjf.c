#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#define MAX 30

int main(int argc, char const *argv[])
{
    int i,j,n,t, p[MAX],bt[MAX],wt[MAX],tat[MAX];
    float awt=0, att =0;
    printf("Enter the number of processes:\n");
    scanf("%d",&n);
    printf("Enter the process number:");
    for (i = 0; i < n; i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter the burst time of process:\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d",&bt[i]);
    }
    //Bubble sort
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if(bt[j]>bt[j+1]){
                t = bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;

                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }

    }
    printf("Process \t Burst Time \t Waiting Time \t Turn around Time \n");
    for ( i = 0; i < n; i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[j];
        awt=awt+wt[i];
        att=att+tat[i];
        printf("%d\t %d\t\t %d\t\t %d \n",p[i],bt[i],wt[i],tat[i]);
    }
    awt = awt /n;
    att=att/n;
    printf("Average waiting time= %f\n",awt);
    printf("Average turn around time= %f",att);
    return 0;
}

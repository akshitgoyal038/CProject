#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int choice,process_name[10],arrival_time[10],burst_time[10],waiting_time[10],finish[10],avg_wait_time,avg_turn_around_time,n,
pending,remain_burst_time[10],time,turn_around_time[10],complete_time[10],x=0,priority[10],pos,count=0,temp,st[10],ft[10],i,j,
total_waiting_time=0,total_around_time=0;
void take_choice(){
    printf("\n\n ************************************  Select Your Choice ****************************************");
    printf("\n 1.  Round Robin");
    printf("\n 2.  Shortest Job First");
    printf("\n 3.  Priority Job First");
    printf("\n 4.  Exit");
    printf("\n Enter your choice");
    scanf("%d",&choice);
}
void output(){
    int i;
    printf("\n\n\n\n Process A.T   B.T    W.T    T.A.T    C.T");
    for(i=0;i<n;i++){
        printf("\n P%d \t %d \t %d \t %d \t %d \t %d\t",process_name[i],arrival_time[i],burst_time[i],waiting_time[i],turn_around_time[i],complete_time[i]);
        if(choice==1){
            total_waiting_time+=waiting_time[i];
            total_around_time+=turn_around_time[i]; 
        }
    }
}
void input(){
    printf("\n Enter number of process");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        process_name[i]=i;
        printf("\n Enter Burst Time of process %d:",process_name[i]);
        scanf("%d",&burst_time[i]);
        remain_burst_time[i]=burst_time[i];
        printf("\n Enter Arrival Time of process %d:",process_name[i]);
        scanf("%d",&arrival_time[i]);
    }
}
// non primptive shortestjob first
void shortest(){
    input();
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(burst_time[i]<burst_time[j])
            {
                temp=arrival_time[i];
                arrival_time[i]=arrival_time[j];
                arrival_time[j]=temp;
                temp=burst_time[i];
                burst_time[i]=burst_time[j];
                burst_time[j]=temp;
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
            st[i]=arrival_time[i];
        else
        st[i]=complete_time[i-1];
        complete_time[i]=st[i]+burst_time[i];
        turn_around_time[i]=complete_time[i]-arrival_time[i];
        waiting_time[i]=turn_around_time[i]-burst_time[i];


  
    }
    output();
    printf("\n\n");
    for(int i=0;i<n;i++){
        total_waiting_time+=waiting_time[i];
        total_around_time+=turn_around_time[i]; 
    }
    printf("Average Waiting time  ======> ");
    printf("%d\n",total_waiting_time/n);
    printf("Average Turn around time  ======> ");
    printf("%d\n",total_around_time/n);
}
// consequetly arrival time
void round_robin(){
    int time_quantum,i;
    input();
    pending=n;
    printf("\n Enter the time Quantum");
    scanf("%d",&time_quantum);
    for(i=0;i<n;i++){
      finish[i]=0;
      waiting_time[i]=0;
    }
    for(time=0,count=0;pending>0;){
        if(remain_burst_time[count]<=time_quantum && remain_burst_time[count]>0){
            time=time+remain_burst_time[count];
            remain_burst_time[count]=0;
            x++;
        }else if(remain_burst_time[count]>0){
            remain_burst_time[count]-=time_quantum;
            time=time+time_quantum;
        }
        if(remain_burst_time[count]==0 && x==1){
            pending--;
            complete_time[count]=time;
            turn_around_time[count]=complete_time[count]-arrival_time[count];
            waiting_time[count]=turn_around_time[count]-burst_time[count];

            x=0; 
        }
        if(count==n) count=0;
        else if(arrival_time[count+1]<=time) count++;
        else count=0;
    }
    output();
        printf("\n\n");
    printf("Average Waiting time  ======> ");
    printf("%d\n",total_waiting_time/n);
    printf("Average Turn around time  ======> ");
    printf("%d\n",total_around_time/n);
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
// pemptive priority
void priority_scheduling(){
  input();
  for(i=0;i<n;i++){
        printf("Enter the priority of process %d",i);
        scanf("%d",&priority[i]);
  }
  for (i = 0; i < n; i++) {
      temp = i;
    for (j = i + 1; j < n; j++) {
      if (priority[j] > priority[temp])
        temp = j;
    }
    swap(&arrival_time[i],&arrival_time[temp]);
    swap(&burst_time[i],&burst_time[temp]);
    swap(&priority[i],&priority[temp]);
    swap(&process_name[i],&process_name[temp]); 
  }
  waiting_time[0] = 0;

  for (i=1;i<n;i++) {
    waiting_time[i] = 0;
    for (j = 0; j < i; j++) {
      waiting_time[i] += burst_time[j];
    }            
  }
  for (i = 0;i < n;i++) {
        turn_around_time[i] = burst_time[i] + waiting_time[i];
  }
  output();
}

int main(){
    while(1){
        take_choice();
        switch(choice){
            case 1: round_robin();
            break;
            case 2: shortest();
            break;
            case 3: priority_scheduling();
            break;
            case 4: exit(0);
            break;
        }
    }
    return 0;
}
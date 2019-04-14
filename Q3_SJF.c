#include<stdio.h>
#include<stdbool.h>

struct Process
{
    int ps;         // process id
    int at;         // arrival time
    int bt;         // burst time
    int tat;        // turn around time
    int wt;         // Waiting time
    bool complete;  // process completed or not
};

void sortQueue(int nProcessQueue, struct Process q[])           // sorting using bubble sort
{
    for (int i = 1; i < nProcessQueue; i++)
    {
        for (int j = 0; j < nProcessQueue - i; j++)
        {
            if (q[j].bt > q[j + 1].bt)
            {
                struct Process temp = q[j + 1];
                q[j + 1] = q[j];
                q[j] = temp;
            }
        }
    }
}

int queueManager(int timer, int n, struct Process ps[])
{
    struct Process queue[n]; // process queue
    int nProcessQueue = 0;   // number of process in the queue
    for (int i = 0, j = 0; i < n; i++)
    {
        if (!ps[i].complete && ps[i].at <= timer)       // if process is not completed and arrival time is less than current time
        {
            queue[j] = ps[i];
            j++;
            nProcessQueue++;
        }
    }
    sortQueue(nProcessQueue, queue);                    // to find the process with shortest burst time
    return queue[0].ps;
}

int findWaitingTime(int n, struct Process ps[])
{
    int timer = 1, firstPs = 0;
    int psID;                               // to store the process ID of the shoretd job
    for (int j = 0; j < n; j++)
    {
        psID = queueManager(timer, n, ps); // return process id of the shortest job
        for (int i = 0; i < n; i++)
        {
            if (psID == ps[i].ps)
            {
                if (firstPs == 0)           // logic for the first process
                {
                    ps[i].wt = 0;
                    firstPs++;
                }
                else                        // logic for rest of the processes
                {
                    ps[i].wt = timer - ps[i].at;
                }
                timer += ps[i].bt;
                ps[i].complete = true;
                timer += 2;                 // time taken for checking and arranging the process according to SJF
                break;
            }
        }
    }
    return timer - 2; // after last process processor does not take any arranging time
}

void findTurnAroundTime(int n, struct Process p[])
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].bt + p[i].wt;       // turnaround time = burst time + waiting time
    }
}

int main()
{
    int n;                              // Number of process to be loaded 
    printf("\nEnter no. of process : ");
    scanf("%d", &n);
    
    struct Process p[n];
    
    //taking input from user
    printf("\nEnter arrival time and burst time of processes : ");
    for(int i =0; i < n; i++){
        bool valid = false;                 // arivial time is valid or not
        printf("\nProcess id = %d\n",i+1);
        p[i].ps = i+1;
        p[i].complete = false;
        while(!valid){
            scanf("%d", &p[i].at);
            if(p[i].at == 0){
                printf("Error, Please enter again a valid arrival time\n");
            }else{
                valid = true;
            }
        }
        scanf("%d", &p[i].bt);
    }
    
    int total_time = findWaitingTime(n, p);                  //To find the waiting time of all the process
    findTurnAroundTime(n, p);               //To find the turnaround time of all the process
    int total_wt = 0, total_tat = 0;
    
    // Displaying output of the program
    printf("\nProcesses \tArrival Time \tBurst Time \tWaiting Time \tTurn Around Time");
    for (int i = 0; i < n; i++)
    {
        total_wt += p[i].wt;
        total_tat += p[i].tat;
        printf("\n %d \t\t %d \t\t %d \t\t %d \t\t %d", p[i].ps, p[i].at, p[i].bt, p[i].wt, p[i].tat);
    }

    printf("\n\nAverage waiting time : %d", total_wt);
    printf("\nAverage turn around time : %d", total_tat);
    printf("\nTotal time taken by the processor : %d\n", total_time); 
    return 0;
}

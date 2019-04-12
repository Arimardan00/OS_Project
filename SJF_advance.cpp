#include <iostream>
#include<algorithm>
using namespace std;

struct Process
{
    int ps;
    int at;
    int bt;
    int tat;
    int wt;
    bool a = false;
};

void sortProcess(int pQueue, struct Process q[])
{
    for (int i = 1; i < pQueue; i++)
    {
        for (int j = 0; j < pQueue - i; j++)
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

void mainQueue(int n,struct Process p[], struct Process queue[], int ct, int &psQueue){
    for(int i = 0; i < n; i++){
        if(!p[i].a  && p[i].at <= ct){
            queue[i] = p[i]; 
            psQueue++;
            cout<<psQueue<<" "<<queue[i].ps<<endl;
        }
    }
    sortProcess(psQueue, queue);
}

void findWaitingTime(int n, struct Process p[])
{
    int currentTime = 0;                 // To manage time
    p[0].wt = 0;                         // waiting time of 1st process
    for (int i = 1; i < n; i++)
    {
        int psQueue = 0;                 // process in the queue
        struct Process queue[n];         // queue :- array of process in the queue
        mainQueue(n, p, queue, currentTime, psQueue);       
        currentTime += queue[0].bt;
        p[i].wt = currentTime;
        p[i].a = true;

    }
}

void findTurnAroundTime(int n, struct Process p[])
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].wt + p[i].bt;
    }
}

void sjf(int n, struct Process p[])
{
    int total_wt = 0, total_tat = 0;
    findWaitingTime(n, p);

    // findTurnAroundTime(n, p);
    // cout << "\nProcesses"
    //      << "\tBurst Time "
    //      << "\tWaiting Time "
    //      << "\tTurn Around Time";
    // for (int i = 0; i < n; i++)
    // {
    //     total_wt += p[i].wt;
    //     total_tat += p[i].tat;
    //     cout << "\n  " << p[i].ps << "\t\t " << p[i].bt << "\t\t " << p[i].wt << "\t\t " << p[i].tat;
    // }
    // cout << "\n\nAverage waiting time : " << (float)total_wt / (float)n;
    // cout << "\nAverage turn around time : " << (float)total_tat / (float)n;
}

int main()
{
    int n = 3;
    // cout << "\nEnter number of process : ";
    // cin >> n;
    struct Process p[3];
    p[0] = {1,0,4};
    p[1] = {2,1,3};
    p[2] = {3,2,1};

    // cout << "\nEnter burst time and arrival time of the process : ";
    // for (i = 0; i < n; i++)
    // {
    //     cout << "\nP" << i + 1 << " : ";
    //     p[i].ps = i + 1;
    //     cin >> p[i].at >> p[i].bt;
    // }

    sjf(n, p);
    return 0;
}
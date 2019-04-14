#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
    int queue[20], n, i, j, seek = 0, max, head, diff;
    float avg;
    cout<<"\nEnter the max range of disk : ";
    cin>>max;
    cout<<"\nEnter the size of queue requests : ";
    cin>>n;
    cout<<"\nEnter the queue of disk portion to be read : ";
    for(i = 1; i <= n; i++ )
        cin>>queue[i];
    cout<<"\nEnter the initial head position : ";
    cin>>head;
    queue[0] = head;
    for(i = 0; i < n; i++){
        diff = abs(queue[i + 1] - queue[i]);
        seek += diff;
        cout<<"\nDisk head move from "<<queue[i]<<" to "<<queue[i+1]<<" with "<<diff<<endl;
    }
    cout<<"\nTotal seek time : "<<seek;
    avg = seek/(float)n;
    cout<<"\nAverage float time : "<<avg;
    return 0;
}
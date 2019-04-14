#include<stdio.h>
#include<stdlib.h>
int main(){
    int queue[10] = {143, 86, 1470, 913, 1774, 948, 1509, 1022, 1750, 130};   
    int max = 4999;         // max track position
    int head = 143;         // current head position
    int distance = 0;           // total distance
    int diff, i;

    for(i = 0; i < 9; i++){
        diff = abs(queue[i+1] - queue[i]);
        distance += diff;
        printf("\nDisk move from %d to %d with %d moves", queue[i], queue[i+1], diff);
    }
    printf("\nTotal distance : %d", distance);
    return 0;
}
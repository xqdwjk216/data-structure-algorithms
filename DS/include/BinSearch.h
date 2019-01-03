#ifndef BINSEARCH_H
#define BINSEARCH_H
#include<iostream>
#include<stdio.h>
using namespace std;

template<typename T>
int search(T num,T arr[],int length)
{

    int maxIndex=length-1;
    int minIndex=0;
    int currentIndex=0;
    int found=0;

    do
    {
        if(arr[currentIndex] == num)
        {
            found = 1;
            break;
        }
        else if(arr[currentIndex] > num )
        {
            maxIndex = currentIndex;
            currentIndex = minIndex+(maxIndex-minIndex)/2;
        }
        else
        {
            minIndex = currentIndex;
            currentIndex = minIndex+(maxIndex-minIndex)/2;
        }

        for(int i=currentIndex; i<=maxIndex; i++)
        {
            if(arr[i] == num)
            {
                found = 1;
                break;
            }
        }

        printf("arr[%d]=%d arr[%d]=%d arr[currentIndex]=%d\n",minIndex,arr[minIndex],maxIndex,arr[maxIndex],arr[currentIndex]);
    }
    while(currentIndex > minIndex && currentIndex < maxIndex);

    if(arr[minIndex] == num || arr[maxIndex] == num)
    {
        found = 1;
    }
    return found;
}

#endif // BINSEARCH_H

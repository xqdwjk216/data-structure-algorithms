#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "common.h"

template<typename T>
void bubble_sort(T arr[], int length)
{
    int currentKey = 0;
    do
    {
        T nowNum = arr[currentKey];
        int nextKey = currentKey + 1;
        do
        {
            T nextNum = arr[nextKey];
            if (nowNum > nextNum)
            {
                T tmp = arr[currentKey];
                arr[currentKey] = arr[nextKey];
                arr[nextKey] = tmp;
                array_dump(arr, length);
            }
            nextKey++;
        }
        while (nextKey < length);
        currentKey++;
    }
    while (currentKey < length - 1);
}

#endif // BUBBLESORT_H

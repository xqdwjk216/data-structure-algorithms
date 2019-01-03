#ifndef SELECTSORT_H
#define SELECTSORT_H
#include "Common.h"
#include "SelectSort.h"
template<typename T>
void selectSort(T arr[],int length) {
    int nextKey = 0;
    do {
        T minNum = arr[nextKey];
        int swapKey = nextKey;
        for(T currentKey = nextKey; currentKey < length; currentKey++) {
            if(arr[currentKey] < minNum) {
                minNum = arr[currentKey];
                swapKey = currentKey;
            }
        }
        if(swapKey != nextKey ) {
            T tmp = arr[nextKey];
            arr[nextKey] = arr[swapKey];
            arr[swapKey] = tmp;
            array_dump(arr,length);
        }
        nextKey++;
    } while(nextKey<length);
}

#endif // SELECTSORT_H

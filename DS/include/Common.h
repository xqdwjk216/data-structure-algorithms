#ifndef COMMON_H
#define COMMON_H

#include<iostream>
using namespace std;

template<typename T>
void array_dump(T arr[],int length) {
    for(int i=0; i<length; i++) {
        cout << arr[i];
        if(i<length-1){
        	cout << ",";
        }
    }
    cout << endl;
}

#endif // COMMON_H
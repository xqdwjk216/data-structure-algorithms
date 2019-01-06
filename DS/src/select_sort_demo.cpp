#include<iostream>
#include "select_sort.h"
using namespace std;

int main()
{
    int a[] = {5, 4, 3, 2, 1};
    int len = 5;
    select_sort(a, len);
    return 0;
}

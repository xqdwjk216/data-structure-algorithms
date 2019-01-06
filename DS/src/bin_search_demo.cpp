#include<iostream>
#include "bin_search.h"
using namespace std;

int main()
{
	int a[] = {1, 2, 3, 4, 5};
	int len = 5;
	int num = 4;
	int found = search(num, a, len);
	cout << (found ? "yes" : "no") << endl;
	return 0;
}

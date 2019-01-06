#ifndef LIST_H
#define LIST_H

#include<iostream>
#define SIZE 10
using namespace std;

class List
{

public:
    List()
    {
    }

    initList(int size)
    {
        this->size = size;
        this->m_data = new int[size];
        for (int i = 0; i < size; i++)
        {
            *(m_data + i) = i;
            length++;
        }
    }

    int getLength()
    {
        return length;
    }

    int getElement(int i)
    {
        if (i > size)
        {
            throw "exception";
        }
        return *(m_data + i) ;
    }

    friend ostream& operator<<(ostream &os, List *list)
    {
        int len = list->getLength();
        for ( int i = 0; i < len; i++)
        {
            cout << list->getElement(i);
            if (i < len - 1)
            {
                cout << ",";
            }
        }
        return os;
    }

private:
    int *m_data;
    int length = 0;
    int size = 0;
};

int main()
{
    List* list = new List();
    list->initList(SIZE);
    cout << list  << endl;

}

#endif
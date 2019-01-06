#include <stdio.h>
#include "stack.h"

int main()
{
    char * str = "[{}][{]}";
    Stack::demoBracket(str);
    return 0;
}

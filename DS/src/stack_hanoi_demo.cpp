#include <stdio.h>
#include "stack.h"

/**
 * 汉诺塔
           |          |        |
          ---         |        |
           |          |        |
         -----        |        |
           |          |        |
        -------       |        |
           x          y        z
*/

int move(int n, char src, char dst) {
    printf("n=%d %d -> %d\n", n, src, dst);
    return 0;
}

int hanoi(int n, char a, char b , char c ) {
    /* 借助c,将a移动到b */
    hanoi(n - 1, a, c, b);
    /* 将a剩下的移动到c,此时a为空,c只有一个 */
    move(n, a, c);
    /* 将n-1个借助a,将b移动到c */
    hanoi(n - 1, b, a, c);
    return 1;
}

/**
 * TODO
 * @param  n [description]
 * @param  a [description]
 * @param  b [description]
 * @param  c [description]
 * @return   [description]
 */
Stack * hanoi_stack(int n, char a, char b, char c) {
    Stack * stack = (Stack *)(malloc(sizeof(Stack)));
    stack->initStack(100);

    if (n == 1) {
        move(n, a, c);
    } else {

    }

    return stack;
}

int main()
{
    Stack * stack = hanoi_stack(3, 'x', 'y', 'z');
    stack->traverse();
    return 0;
}

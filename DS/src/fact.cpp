#include <stdio.h>
#include <assert.h>
#include "time.h"

/**
 * 递归实现阶乘
 * @param  n [description]
 * @return   [description]
 */
int fact1(int n) {
    assert(n >= 0);
    if (n <= 1) {
        return 1;
    }
    return n * fact1(n - 1);
}

/**
 * 非递归
 * @param  n [description]
 * @return   [description]
 */
int fact2(int n) {
    assert(n >= 0);
    if (n <= 1) {
        return 1;
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

/**
 * 尾递归
 * @param  n [description]
 * @return   [description]
 */
int fact3(int n, int a = 1) {
    assert(n >= 0);
    if (n == 0) {
        return 1;
    } else if ( n == 1 ) {
        return a;
    }
    return fact3(n - 1, n * a);
}

/**
 * 递归斐波那契数列
 * @param  n [description]
 * @return   [description]
 */
int fib1(int n) {
    if (n < 3) {
        return 1;
    }
    return fib1(n - 1) + fib1(n - 2);
}

/**
 * 非递归斐波那契数列
 * 1 1 2 3 5 8
 * @param  n [description]
 * @return   [description]
 */
int fib2(int n) {
    if (n < 3) {
        return 1;
    }
    int res = 0, a = 1, b = 1;
    for ( int i = 3; i <= n; i++) {
        res = a + b;
        /* 将上上一个数保存到a */
        a = b;
        /* 将上一个数保存到b */
        b = res;
    }
    return res;
}

/**
 * 尾递归斐波那契数列
 * @param  n [description]
 * @param  a [上上一个数]
 * @param  b [上一个数]
 * @return   [description]
 */
int fib3(int n, int a = 1, int b = 1) {
    if (n <= 2) {
        return b;
    }
    return fib3(n - 1, b, a + b);
}

/* 将n从a柱挪到b柱 */
void move(int n, char a, char b) {
    printf("n=%d %c->%c\n", n, a, b);
}

/**
 * 汉诺塔
           |          |        |
          ---         |        |
           |          |        |
         -----        |        |
           |          |        |
        -------       |        |
           x          y        z
 * 挪动第n层,从a->c,借助b
 * @param n [description]
 */
void hanoi(int n, char a, char b, char c)
{
    if (n == 1) {
        move(n, a, c);
    } else {
        /* 先将n-1层挪走,此时a只剩一个,c为空,b剩余n-1个 */
        hanoi(n - 1, a, b, c);
        /* 移动后a为空 */
        move(n, a, c);
        /* 借助a将b移到c */
        hanoi(n - 1, b, a, c);
    }
}

int main() {
    clock_t start = clock();
    int res = fact1(5);
    clock_t finish = clock();
    printf("%d ellapse:%lu\n", res, finish - start);

    start = clock();
    res = fact2(5);
    finish = clock();
    printf("%d ellapse:%lu\n", res, finish - start);

    start = clock();
    res = fact3(5);
    finish = clock();
    printf("%d ellapse:%lu\n", res, finish - start);

    start = clock();
    res = fib1(6);
    finish = clock();
    printf("%d ellapse:%lu\n", res, finish - start);

    start = clock();
    res = fib2(6);
    finish = clock();
    printf("%d ellapse:%lu\n", res, finish - start);

    start = clock();
    res = fib3(6);
    finish = clock();
    printf("%d ellapse:%lu\n", res, finish - start);

    hanoi(3, 'x', 'y', 'z');
}
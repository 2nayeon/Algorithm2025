#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <time.h>
#include <stdlib.h>
#define DNUM 50
#define random(n) rand() % n
#define randomize() srand((unsigned int) time(NULL))

main()
{
    int data[DNUM], i, psum = 0, nsum = 0;

    randomize();
    for (i = 0; i < DNUM; i++)
        data[i] = -100 + random(201); //-100부터 100까지의 난수 생성


        for (i = 0; i < DNUM; i++) {
            printf("%5d ", data[i]);
            if ((i + 1) % 10 == 0) printf("\n");
            if (data[i] > 0) psum = psum + data[i];
            else nsum = nsum + data[i];
        }
    printf("\nSum of positive number : %d\n", psum);
    printf("Sum of negative number : %d\n", nsum);
}
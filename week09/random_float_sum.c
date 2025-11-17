#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 20
#define random(n) rand() % n
#define randomize() srand((unsigned int) time(NULL))

main()
{
    float rdata[NUM], fsum = 0.0;
    int i, isum = 0, temp;
    randomize(); 
    // randomize()가 없을 경우 rand()는 항상 같은 난수를 생성

    for (i = 0; i < NUM; i++) {
        rdata[i] = random(100) + random(100) / 100.0;
        printf("%6.2f  ", rdata[i]);
        if ((i + 1) % 7 == 0) printf("\n");
    }

    for (i = 0; i < NUM; i++) {
        temp = rdata[i]; // 정수부분 추출(float->int)
        isum += temp; 
        fsum += (rdata[i] - temp);
    }

    printf("\n\n정수부분의 합 : %d\n", isum);
    printf("\n소수부분의 합 : %.3f\n", fsum);
}
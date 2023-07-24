#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main()
{
    int num,l=1,u=4;
    srand(time(0));
    num=rand()%(u-l+1)+l;
    printf("%d ", num);
}
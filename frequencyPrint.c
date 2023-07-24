#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int arr[20],num,u=99,l=1,count=0,arr1[100],digit;
    srand(time(0));
    FILE *fp=NULL;
    fp=fopen("r.txt","w+");
    if(fp==NULL)
    {
        printf("Error in creating a file\n");
        exit(0);
    }
    for(int i=0;i<20;i++)
    {
        num=rand()%(u-l+1)+l;
        fprintf(fp,"%d ",num);
    }
    rewind(fp);
    for(int i=0;i<20;i++)
    {
        fscanf(fp,"%d ",&arr[i]);
    }
    printf("The array elements are\n");
    for(int i=0;i<20;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("The frequency of occurences of elements are\n");
    for(int i=0;i<20;i++)
    {
        num=arr[i];
        while(num!=0)
        {
           digit=num%10;
           arr1[digit]++;
           num/=10;
        }
    }
    for(int i=0;i<100;i++)
    {
        printf("%d's occurences is %d\n",i,arr1[i]);
    }
}
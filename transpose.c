#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
    FILE *fp=NULL;
    fp=fopen("go.txt","w+");
    if(fp==NULL)
    {
        printf("Error\n");
        exit(0);
    }
    
    int m,n;
    int l=1,u=10,num;
    int matrix[100][100];
    printf("Enter the value of m and n\n");
    scanf("%d %d",&m ,&n);
    srand(time(0));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
           num=rand()%(u-l+1)+l;
           fprintf(fp,"%d ",num);
        }
    }
    rewind(fp);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            fscanf(fp,"%d",&matrix[i][j]);
        }
    }
    int matrix1[100][100];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
          if(i==j)
          {
            matrix1[i][j]=matrix[i][j];
          }
          else{
            matrix1[j][i]=matrix[i][j];
          }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d ",matrix1[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
}
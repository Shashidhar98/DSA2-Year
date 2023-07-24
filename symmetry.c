#include<stdio.h>
#include<stdlib.h>
int solve(int matrix[][20],int row,int col)
{
    int matrix1[20][20];
    for(int i=0;i<col;i++)
    {
        for(int j=0;j<row;j++)
        {
           matrix1[i][j]=matrix[j][i];
        }
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
          if(matrix[i][j]!=matrix1[i][j])
          {
            return 0;
          }
        }
    }
    return 1;
}
int main()
{
    int row,col,num,u=20,l=1,matrix[20][20];
    printf("Enter the row and column value\n");
    scanf("%d %d",&row,&col);
    if(row!=col)
    {
        printf("Can't possible to find out symmetry\n");
        exit(0);
    }
    printf("Enter the elements of the matrix\n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf(" %d",&matrix[i][j]);
        }
    }
    printf("Matrix is \n");
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
   int b=solve(matrix,row,col);
   if(b==1)
   {
    printf("yes\n");
   }
   else{
    printf("no");
   }
}
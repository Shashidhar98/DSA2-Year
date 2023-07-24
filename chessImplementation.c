#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void display(char board[][9],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}

void movPawn(char board[][9],int r,int c)
{
    int newr,newc;

    if(board[r][c]=='P' && board[r+1][c]=='-')
    {
        printf("%d %d\n",r+1,c);
    }
    else if(board[r][c]=='P' && board[r+1][c]!='-')
    {
        printf("White pawn cannot be moved\n");
    }

    if(board[r][c]=='p' && board[r-1][c]=='-')
    {
        printf("%d %d\n",r-1,c);
    }
    else if(board[r][c]=='p' && board[r-1][c]!='-')
    {
        printf("Black pawn cannot be moved\n");
    }
}

void movRook(char board[][9],int r,int c)
{
    int newc=c-1;
    while(newc>=1)
    {
        if(board[r][newc]=='-')
        {
            printf("%d %d\n",r,newc--);
        }
        else if(board[r][newc]!='-')
        {
            break;
        }
    }

        int newr=r-1;
        while(newr>0)
        {
            if(board[newr][c]=='-')
            {
                printf("%d %d\n",newr--,c);
            }
            else if(board[newr][c]!='-')
            {
                  break;
            }
        }
        
        newc=c+1;
        while(newc<9)
        {
            if(board[r][newc]=='-')
            {
               printf("%d %d\n",r,newc++);
            }
            else if(board[r][newc]!='-')
            {
              break;
            }
        }
        newr=r+1;
        while(newr<9)
        {
            if(board[newr][c]=='-')
            {
                printf("%d %d\n",newr++,c);
            }
            else if(board[newr][c]!='-')
            {
                  break;
            }
        }
}

void movBishop(char board[][9],int r,int c)
{
    int newr=r-1;
    int newc=c-1;
    while((newr>0 && newr<9) && (newc>0 && newc<9))
    {
      if(board[newr][newc]=='-')
      {
        printf("%d %d\n",newr--,newc--);
      }
      else if(board[newr][newc]!='-')
      {
        break;
      }
    }
    
    newr=r+1;
    newc=c-1;
    while((newr>0 && newr<9) && (newc>0 && newc<9))
    {
      if(board[newr][newc]=='-')
      {
        printf("%d %d\n",newr++,newc--);
      }
      else if(board[newr][newc]!='-')
      {
        break;
      }
    }

    newr=r-1;
    newc=c+1;
    while((newr>0 && newr<9) && (newc>0 && newc<9))
    {
      if(board[newr][newc]=='-')
      {
        printf("%d %d\n",newr--,newc++);
      }
      else if(board[newr][newc]!='-')
      {
        break;
      }
    }

    newr=r+1;
    newc=c+1;
    while((newr>0 && newr<9) && (newc>0 && newc<9))
    {
      if(board[newr][newc]=='-')
      {
        printf("%d %d\n",newr++,newc++);
      }
      else if(board[newr][newc]!='-')
      {
        break;
      }
    }
}
int main()
{
    char board[9][9],a;
    int ch,r,c;
    for(int i=1;i<9;i++)
    {
        for(int j=1;j<9;j++)
        {
            board[i][j]='-';
        }
    }
    while(1)
    {
        printf("Press 1:piecePlacing  2:End\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        if(ch==2)
        {
            break;
        }
        switch(ch)
        {
          case 1:printf("Enter the row and column value for piece to be placed\n");
                 scanf("%d %d",&r,&c);
                 if((r<=0 || r>8) && (c<=0 || c>8))
                 {
                    printf("Invalid position\n");
                    break;
                 }
                 printf("Enter the piece name(Capital-White,small-black)\n");
                 printf("Rook-r/R Bishop-b/B Knight-h/H  King-k/K  Queen-q/Q Pawns-p/P \n");
                 scanf(" %c",&board[r][c]);
                 break;
          default: printf("Invalid case\n");
                  break;
        }
    }
    printf("Board looks like\n");
    display(board,9);

    while(1)
    {
        printf("Enter 1:forMovements  2:End\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        if(ch==2)
        {
            break;
        }
        switch(ch)
        {
            case 1:printf("Enter the pieceName Row and Columns value for its movements\n");
                   scanf(" %c",&a);
                   scanf("%d %d",&r,&c);
                   if(a=='p' || a=='P')
                   {
                     printf("Pawn can be moved to:\n");
                     movPawn(board,r,c);
                   }
                   else if(a=='r' || a=='R')
                   {
                    printf("Rook can be moved to:\n");
                    movRook(board,r,c);
                   }
                   else if(a=='B' || a=='b')
                   {
                    printf("Bishop can be moved to\n");
                    movBishop(board,r,c);
                   }
                   break;
            default: printf("Invalid case\n");
                    break;
        }
        
    }

}
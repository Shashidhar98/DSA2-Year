#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node{
    int data;
    struct node* link;
};
typedef struct node* NODE;
int countNodes(NODE head);
NODE createNode(int value)
{
    NODE newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->link=NULL;
    return  newnode;
}
NODE insertEnd(NODE head,int value)
{
   NODE newnode,cur;
   newnode=createNode(value);
   if(head==NULL)
   {
    head=newnode;
   }
   else{
       cur=head;
       while(cur->link!=NULL)
       {
        cur=cur->link;
       }
       cur->link=newnode;
   }
   return head;
}
void Display(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("SLL is empty\n");
    }
    else{
          cur=head;
          while(cur!=NULL)
          {
            printf("%d ",cur->data);
            cur=cur->link;
          }
    }
    printf("\n");
}
void bubbleSort(NODE head)
{
    NODE cur2=head;
    int count=countNodes(head),temp;
    for(int i=0;i<count-1;i++)
    {
        for(int j=0;j<count-i-1;j++)
        {
           if(cur2->data>=(cur2->link)->data)
           {
              temp=cur2->data;
              cur2->data=(cur2->link)->data;
              (cur2->link)->data=temp;
           } 
           cur2=cur2->link;
        }
        cur2=head;
    }
}
int countNodes(NODE head)
{
    NODE cur;
    int count=0;
    if(head==NULL)
    {
        return 0;
    }
    else{
        cur=head;
        while(cur!=NULL)
        {
            count++;
            cur=cur->link;
        }
    }
    return count;

}
int main()
{
    NODE head=NULL;
    int ch,count;
    int n,m,value,l=1,h=30;
    printf("Enter the value of count of random numbers\n");
    scanf("%d",&m);
    while(1)
    {
        printf("Enter the value\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: srand(time(0));
                   for(int i=0;i<m;i++)
                   {
                     value=rand()%(h-l+1)+l;
                     head=insertEnd(head,value);
                   }
                   break;
            case 2:Display(head);
                   break;
            case 3:bubbleSort(head);
                   break;
            case 4:count=countNodes(head);
                   printf("Number of nodes are%d \n",count);
                   break;
            case 5:exit(0);
            default: printf("Invalid\n");
                    break;
        }
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* lLink;
    struct node* rLink;
};
typedef struct node *NODE;
NODE createNode()
{
  NODE newnode;
  int a;
  printf("Enter the data (Enter -1 for no node)\n");
  scanf("%d",&a);
  if(a==-1)
  {
    return NULL;
  }
  newnode=malloc(sizeof(struct node));
  newnode->data=a;
  printf("Enter the left node of %d\n",a);
  newnode->lLink=createNode();
  printf("Enter the right node of %d\n",a);
  newnode->rLink=createNode();
  return newnode;
}
void inOrder(NODE root)
{
    if(root==NULL)
    {
        return ;
    }

    inOrder(root->lLink);
    printf("%d - ",root->data);
    inOrder(root->rLink);
}
void preOrder(NODE root)
{
    if(root==NULL)
    {
        return;
    }

    printf("%d - ",root->data);
    preOrder(root->lLink);
    preOrder(root->rLink);
}
void postOrder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
   
    postOrder(root->lLink);
    postOrder(root->rLink);
    printf("%d - ",root->data);

}
int main()
{
    NODE root=NULL;
    root=createNode();
    inOrder(root);
    printf("\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* lLink,*rLink;
    int height;
};

int max(int a,int b)
{
    return (a>b)? a: b;
}

int getHeight(struct node* n)
{
    if(n==NULL)
    {
        return 0;
    }
    return n->height;
}

struct node* createNode(int value)
{
  struct node* newnode;
  newnode=malloc(sizeof(struct node));
  newnode->data=value;
  newnode->rLink=newnode->lLink=NULL;
  newnode->height=1;
  return newnode;
}
struct node* insertNode(struct node* root,int value)
{
    if(root==NULL)
    {
        root=createNode(value);
    }
    else if(value<root->data)
    {
        root->lLink=insertNode(root->lLink,value);
    }
    else{
        root->rLink=insertNode(root->rLink,value);
    }
    root->height=max(getHeight(root->lLink),getHeight(root->rLink))+1;

    return root;
}
void preOrder(struct node* root,int arr[8])
{
    if(root==NULL)
    {
        return ;
    }
    arr[root->height]++;
    printf("%d - ",root->data);
    preOrder(root->lLink,arr);
    preOrder(root->rLink,arr);
}

int main()
{
  struct node* root=NULL;
  int key;
  int arr[8]={0,0,0,0,0,0,0,0};
  root=insertNode(root,10);
  root=insertNode(root,5);
  root=insertNode(root,20);
  printf("PreOrder traversal of the bst is\n");
  preOrder(root,arr);
  printf("\n");
    for(int i=1;i<8;i++)
   {
     printf("The number of nodes in the %d level is %d\n",i,arr[i]);
   }
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int value)
{
    struct node* newnode;
    newnode=malloc(sizeof(struct node));
    newnode->data=value;
    newnode->left=newnode->right=NULL;
    return newnode;
}
struct node* insertNode(struct node* root,int value)
{
    if(root==NULL)
    {
        root=createNode(value);
    }
    else if(value>root->data)
    {
        root->right=insertNode(root->right,value);
    }
    else{
        root->left=insertNode(root->left,value);
    }
    return root;
}
void preOrder(struct node* root)
{
    if(root==NULL)
    {
        return ;
    }

    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

struct node* findMin(struct node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

struct node* deleteNode(struct node* root,int value)
{
    if(root==NULL)
    {
        return root;
    }
    else if(value>root->data)
    {
        root->right=deleteNode(root->right,value);
    }
    else if(value<root->data)
    {
        root->left=deleteNode(root->left,value);
    }
    else{
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            root=NULL;
        }
        else if(root->right==NULL)
        {
            struct node* temp=root;
            root=root->left;
            free(temp);
        }
        else if(root->left==NULL)
        {
            struct node* temp=root;
            root=root->right;
            free(temp);
        }
        else{
            struct node* temp=findMin(root->right);
            root->data=temp->data;
            root->right=deleteNode(root->right,temp->data);
        }
    }
    return root;
}

int main()
{
   struct node* root=NULL;
   FILE* fp=NULL;
   fp=fopen("doo.txt","w+");
   if(fp==NULL)
   {
    printf("Error in creating a file\n");
    exit(0);
   }
   int n,l=1,u=10,num;
   printf("Enter the number of random numbers\n");
   scanf("%d",&n);
   srand(time(0));
   for(int i=0;i<n;i++)
   {
    num=rand()%(u-l+1)+l;
    fprintf(fp,"%d ",num);
   }
   rewind(fp);
   for(int i=0;i<n;i++)
   {
    fscanf(fp,"%d ",&num);
    root=insertNode(root,num);
   }
   preOrder(root);
   printf("\nEnter the value to be deleted\n");
   scanf("%d",&num);
   root=deleteNode(root,num);
   preOrder(root);
}
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
    int height;
};
struct node* leftRotate(struct node* root);
struct node* rightRotate(struct node* root);
int getHeight(struct node* n);
int max(int a,int b)
{
    return (a>b)? a:b;
}
int getBF(struct node* n)
{
    if(n==NULL)
    {
        return 0;
    }

    return (getHeight(n->left) - getHeight(n->right));
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
    struct node* newnode=(struct node*) malloc(sizeof(struct node));
    newnode->left=newnode->right=NULL;
    newnode->data=value;
    newnode->height=1;
    return newnode;
}

struct node* rightRotate(struct node* y)
{
    struct node* x=y->left;
    struct node* T2=x->right;

    x->right=y;
    y->left=T2;

    y->height=max(getHeight(y->left),getHeight(y->right))+1;   //Think it if exchange happened means result coming  wrong
    x->height=max(getHeight(x->right),getHeight(x->left))+1;
    return x;
}

struct node* leftRotate(struct node* x)
{
    struct node* y=x->right;
    struct node* T2=y->left;

    y->left=x;
    x->right=T2;
    
    x->height=max(getHeight(x->left),getHeight(x->right))+1; 
    y->height=max(getHeight(y->right),getHeight(y->left))+1;

    return y;

}


struct node* insertNode(struct node* root,int value)
{
    if(root==NULL)
    {
        return createNode(value);
    }
    else if(value>root->data)
    {
        root->right=insertNode(root->right,value);
    }
    else if(value<root->data)
    {
        root->left=insertNode(root->left,value);
    }
    
    root->height=max(getHeight(root->left),getHeight(root->right))+1;
    //LL 
    if(getBF(root)>1 && value<root->left->data){
        return rightRotate(root);
    }
    //RR
    if(getBF(root)<-1 && value>root->right->data)
    {
        return leftRotate(root);
    }
    //LR
    if(getBF(root)>1 && value>root->left->data)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    //RL
    if(getBF(root)<-1 && value<root->right->data)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d - ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int main()
{
    struct node* root=NULL;
    root=insertNode(root,1);
    root=insertNode(root,2);
    root=insertNode(root,3);
    root=insertNode(root,4);
    root=insertNode(root,5);
    preOrder(root);
}
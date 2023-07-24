#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* createNode(node* root)
{
    int x;
    cout<< "Enter the data(-1 for no node)" << endl;
    cin>> x;
    if(x==-1)
    {
        return NULL;
    }
    root=new node(x);
    cout<< "Enter the information for left node of nodeValue "<< x << endl;
    root->left=createNode(root->left);
    cout<< "Enter the information for right node of nodeValue "<< x << endl;
    root->right=createNode(root->right);
    return root;
}

void buildFromLevelOrder(node* &root)
{
    queue<node*> q;
    cout<< "Enter the root node data" << endl;
    int data;
    cin>> data;
    root=new node(data);
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();

        cout<< "Enter the data for left node of " << temp->data << endl;
        int leftData;
        cin>> leftData;

        if(leftData!=-1)
        {
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<< "Enter the data for right node of " << temp->data << endl;
        int rightData;
        cin>> rightData;

        if(rightData!=-1)
        {
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}


void levelOrdertraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    node* temp=NULL;

    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        
        if(temp==NULL)
        {
            cout<< endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<< temp->data << " ";
            if(temp->left)
            {
                q.push(temp->left);
            }

            if(temp->right)
            {
                q.push(temp->right);
            } 
        }
    }

}
int main()
{
    node* root=NULL;
    //root=createNode(root);
    //cout<< "The level order traversal of binary tree is " << endl;
    //levelOrdertraversal(root);
    buildFromLevelOrder(root);
    cout<< endl << "The level order traversal is " << endl;
    levelOrdertraversal(root);

}
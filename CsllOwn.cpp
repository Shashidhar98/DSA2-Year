#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data=data;
        this->next=this;
    }

    ~Node()
    {
        cout<< "The node is deleted with value " << this->data << endl;
    }
};

void countNodes(Node* &tail,int& count);

void insertEnd(Node* &tail,int value)
{
    Node* newNode=new Node(value);
    if(tail==NULL)
    {
       tail=newNode;
    }
    else{
        newNode->next=tail->next;
        tail->next=newNode;
        tail=newNode;
    }
}
void insertFront(Node* &tail,int value)
{
    Node* newNode=new Node(value);
    if(tail==NULL)
    {
        tail=newNode;
    }
    else{
        Node* cur=tail->next;
        newNode->next=cur;
        tail->next=newNode;
    }
}

void insertPosition(Node* &tail,int value,int pos)
{
    int count=0;
    countNodes(tail,count);

    if(pos<1 || pos>(count+1))
    {
        cout<< "Invalid position" << endl;
    }
    else if(pos==1)
    {
        insertFront(tail,value);
    }
    else if(pos==(count+1))
    {
        insertEnd(tail,value);
    }
    else{
        int i=1;
        Node* cur=tail->next;
        Node* newNode=new Node(value);
        while(cur!=tail)
        {
            if(i==(pos-1))
            {
                break;
            }
            i++;
            cur=cur->next;
        }
        newNode->next=cur->next;
        cur->next=newNode;
    }
}

void countNodes(Node* &tail,int &count)
{
    if(tail==NULL)
    {
        count=0;
    }
    else{
        Node* cur=tail->next;
        while(cur!=tail)
        {
            count++;
            cur=cur->next;
        }
        count++;
    }
}

void display(Node* &tail)
{
    if(tail==NULL)
    {
        cout<< "CSLL is empty" << endl;
    }
    else{
        Node* cur=tail->next;
        while(cur!=tail)
        {
            cout<< cur->data << " ";
            cur=cur->next;
        }
        cout<< cur->data <<endl;
    }
}

void deleteEnd(Node* &tail)
{
    if(tail==NULL)
    {
        cout<< "CSLL is empty" << endl;
    }
    else if(tail->next==tail)
    {
        delete tail;
        tail=NULL;
    }
    else{
        Node* cur=tail->next;
        while(cur->next!=tail)
        {
            cur=cur->next;
        }
        cur->next=tail->next;
        tail->next=NULL;
        delete tail;
        tail=cur;
    }
}

void deleteFront(Node* &tail)
{
    if(tail==NULL)
    {
        cout<< "CSLL is empty" << endl;
    }
    else if(tail->next==tail)
    {
        delete tail;
        tail=NULL;
    }
    else{
        Node* cur=tail->next;
        tail->next=cur->next;
        cur->next=NULL;
        delete cur;
    }
}

void deletePosition(Node* &tail,int pos)
{
    int count=0;
    countNodes(tail,count);
    if(pos<1 || pos>count)
    {
        cout<< "The position is invalid" << endl;
    }
    else if(pos==1)
    {
        deleteFront(tail);
    }
    else if(pos==count)
    {
        deleteEnd(tail);
    }
    else{
        int i=1;
        Node* cur=tail->next,*prev=NULL;
        while(cur!=NULL)
        {
            if(i==pos)
            {
                break;
            }
            prev=cur;
            cur=cur->next;
            i++;
        }
        prev->next=cur->next;
        cur->next=NULL;
        delete cur;
    }
}

int main()
{
    Node *tail=NULL;
    int ch,value,count=0,pos;
     while(1)
    {
        cout<< "1:InsertEnd  2:InsertFront 3:InsertPosition 4:DeleteEnd 5:DeleteFront 6:DeletePosition 7:Display 8:CountNodes 9:Exit"<<endl << endl;
        cout<< "Enter your choice"<< endl;
        cin>> ch;
        switch(ch)
        {
            case 1: cout<< "Enter the value to be inserted"<< endl;
                    cin>> value ;
                    insertEnd(tail,value);
                    break;
            case 2: cout<< "Enter the value to be inserted"<< endl;
                    cin>> value ;
                    insertFront(tail,value);
                    break;
            case 3: cout<< "Enter the value and also position to be inserted"<< endl;
                    cin>> value >> pos;
                    insertPosition(tail,value,pos);
                    break;
            case 4: deleteEnd(tail);
                    break;
            case 5: deleteFront(tail);
                    break;
            case 6: cout<< "Enter the position to be deleted"<< endl;
                    cin>> pos;
                    deletePosition(tail,pos);
                    break;
            case 7: display(tail);
                    break;
            case 8: count=0;
                    countNodes(tail,count);
                    cout<< "The number of nodes in CSLL is " << count << endl;
                    break;
            case 9: exit(0);
            default: cout<< "Invalid position" <<endl;
                     break;
            
        }
    }

}
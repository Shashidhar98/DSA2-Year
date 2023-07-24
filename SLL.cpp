#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int data){  //Constructor has been called every time object is created
      this->data=data;
      this->next=NULL;
    }

    ~node(){
        int value=this->data;
        cout<< endl << "The node is deleted with value "<< this->data << endl; 
    }
};

int countNodes(node* &head);



void display(node* head)
{
    node* cur=head;
    if(head==NULL)
    {
        cout<< "SLL is empty" << endl;
    }
    else {
        while(cur!=NULL)
        {
            cout<< cur->data << " " ;
            cur=cur->next;
        }
    }
}

void insertFront(node* &head,int value)           //insert@head
{
    node* newnode=new node(value);
    newnode->next=head;
    head=newnode;
}

void insertEnd(node* &tail,int value)             //insert@tail
{
    node* newnode=new node(value);
    tail->next=newnode;
    tail=newnode;
}

void insertPosition(node* &head,node* &tail,int value,int pos)
{
    int count=countNodes(head);
    if(pos>0 && pos<=count+1)
    {
       if(pos==1)
       {
          insertFront(head,value);
       }
       else if(pos==count+1)
       {
        insertEnd(tail,value);
       }
       else{
            node* newnode=new node(value);
            node* cur=head;
            int c=1;
            while(c<(pos-1))
            {
              cur=cur->next;
              c++;
            }
            newnode->next=cur->next;
            cur->next=newnode;
       }
    }
    else{
        cout<< "Invalid position" << endl;
    }
}

int countNodes(node* &head)
{
    int count=0;
    node* cur=head;
    if(head==NULL)
    {
        return 0;
    }
    while(cur!=NULL)
    {
        count++;
        cur=cur->next;
    }
    return count;
}

void deleteFront(node* &head,node* &tail)
{
   if(head->next==NULL)
   {
        delete head;
        head=NULL;
        tail=NULL;
   }
   else{
        node* temp=head;
        head=head->next;
        delete temp;
   }
}

void deletePosition(node* &head,node* &tail,int position)
{
   int count=countNodes(head); 
   if(position>0 && position<=count)
   {
    if(position==1 && count==1)
    {
        deleteFront(head,tail);
        tail=NULL;
    }
    else if(position==1)
    {
        deleteFront(head,tail);
    }
    else
    {
       int i=1; 
       node* cur=head,*prev=NULL;
       while(cur!=NULL)
       {
           if(i==position)
           {
            break;
           }
           prev=cur;
           cur=cur->next;
           i++;
       }
       prev->next=cur->next;
       if(cur->next==NULL)
       {
        tail=prev;
       }
       delete cur;
    }
   } 
   else{
    cout<< "Invalid position" << endl;
   } 
}
int main()
{
   //Object creation
   node* head=new node(10);
   //insertFront(head,20);
   //display(head);
   //cout<< endl;
   node* tail=head;
   /*insertEnd(tail,20);
   //display(head);
   //cout<< endl;
   insertEnd(tail,30);
   display(head);
   cout<< endl;
   insertPosition(head,tail,50,3);
   display(head);*/
   insertEnd(tail,20);
   insertEnd(tail,30);
    cout<<endl;
   display(head);
   deletePosition(head,tail,2);
   cout <<endl;
   display(head);
   deletePosition(head,tail,1);
   display(head);
   deletePosition(head,tail,1);
   display(head);


}
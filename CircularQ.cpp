#include<iostream>
using namespace std;
class Queue{
    public:
    int *arr;
    int size;
    int rear;
    int front;

    Queue(int size)
    {
        this->size=size;
        arr=new int[this->size];
        this->rear=this->front=-1;
    }

    void enqueue(int data)
    {
        if(this->rear==-1 && this->front==-1)
        {
            this->rear=this->front=0;
            this->arr[this->rear]=data;
        }
        else if((this->rear+1)%this->size==this->front)
        {
            cout<< "Queue is full " <<endl;
        }
        else{
            this->rear=(this->rear+1)%this->size;
            this->arr[this->rear]=data;
        }
    }

    int dequeue()
    {
        int ans=-1;
        if(this->rear==-1 && this->front==-1)
        {
            cout<< "Queue is empty" << endl;
        }
        else if(this->rear==this->front)
        {
            ans=this->arr[this->front];
            this->front=this->rear=-1;
        }
        else{
            ans=this->arr[this->front];
            this->front=(this->front+1)%this->size;
        }
        return ans;
    }

    int getFront()
    {
        if(this->rear==-1 && this->front==-1)
        {
            cout<< "Queue is empty"<< endl;
            return -1;
        }
        else{
            return this->arr[this->front];
        }
    }
};
int main()
{
    Queue q(4);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    int ans;
    ans=q.dequeue();
    if(ans!=-1)
    {
        cout<< "Dequeued element is " << ans << endl;
    }
    ans=q.getFront();
    if(ans!=-1)
    {
        cout<< "Front element is " << ans << endl;
    }
    ans=q.dequeue();
    if(ans!=-1)
    {
        cout<< "Dequeued element is " << ans << endl;
    }
    ans=q.getFront();
    if(ans!=-1)
    {
        cout<< "Front element is " << ans << endl;
    }
    q.enqueue(100);
    q.enqueue(200);
    cout<< q.arr[0] << endl;
    cout<< q.arr[1] << endl;
    cout<< q.arr[2] << endl;
    cout<< q.arr[3] << endl;
    
}
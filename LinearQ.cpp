#include<iostream>
using namespace std;
class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;
    Queue(int size)
    {
        this->size=size;
        arr=new int[this->size];
        this->front=this->rear=-1;
    }

    void enqueue(int data)
    {
        if(this->rear==this->size-1)
        {
            cout<< "Queue is full " << endl;
        }
        else if(this->rear==-1 && this->front==-1)
        {
            this->front=this->rear=0;
            this->arr[this->rear]=data;
        }
        else{
            this->rear++;
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
            this->rear=this->front=-1;
        }
        else{
            ans=this->arr[this->front];
            this->front++;
        }
        return ans;
    }

    int getFront()
    {
        if(this->rear==-1 && this->front==-1)
        {
            cout<< "Queue is empty" << endl;
            return -1;
        }
        else{
            return this->arr[this->front];
        }
    }
};

int main()
{
    Queue q(3);
    q.enqueue(10);
    q.enqueue(20);
    int ans=q.dequeue();
    if(ans!=-1)
    {
        cout<< "The dequeued element is " << ans << endl;
    }
    cout<< q.front << endl;
    cout<< q.rear << endl;
    q.enqueue(30);
    q.enqueue(40);
    ans=q.getFront();
    if(ans!=-1)
    {
        cout<< "Front element is " << ans ;
    }
}
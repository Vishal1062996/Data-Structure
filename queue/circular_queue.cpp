#include<iostream>
using namespace std;

class circularQueue{
    private:
    int size;
    int front;
    int rear;
    int *q;
    public:
    circularQueue(){size=10;front=rear=0;q=new int[size];}
    circularQueue(int size){this->size=size;front=rear=0;q=new int[this->size];}

    void enqueue(int x);
    int dequeue();
    void display();
};

void circularQueue::enqueue(int x){
    if((rear+1)%size == front){
        cout << "queue is full"<< endl;
    }
    else{
        rear = (rear+1)%size;
        q[rear]= x;
    }
}

int circularQueue::dequeue(){
    int x=-1;
    if(rear==front){
        cout << "queue is empty" << endl;
    }
    else{
        front = (front+1)%size;
        x = q[front];
    }
    return x;
}

void circularQueue::display(){
    for(int i=front+1; i!=(rear+1)%size; i=(i+1)%size){
        cout << q[i] << " ";
    }
    cout << endl;
}

int main(){
    circularQueue cq(5);
    cq.enqueue(7);
    cq.enqueue(6);
    cq.enqueue(4);
    cq.enqueue(1);
    cq.dequeue();
    cq.dequeue();
    cq.enqueue(0);

    cq.display();
    
    // cout << cq.dequeue() << endl;
    // cq.display();


    return 0;
}
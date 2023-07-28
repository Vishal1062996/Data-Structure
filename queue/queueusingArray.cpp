#include<iostream>
using namespace std;

class queue{
    private:
    int size;
    int front;
    int rear;
    int *q;
    public:
    queue(int s);

    void enqueue(int x);
    int dequeue();
    void display();
};

queue::queue(int s){
   size = s;
   front=rear=-1;
   q = new int[size]; 
}

void queue::enqueue(int x){
    if(rear==size-1){
        cout << "Queue is overflow";
    }
    else{
        rear++;
        q[rear]=x;
    }
}

int queue::dequeue(){
    int x=-1;
    if(rear==front){
    }
    else{
        front++;
        x=q[front];
    }
    return x;
}

void queue::display(){
    for(int i=front+1; i<=rear; i++){
        cout << q[i] << " ";
    }
    cout << endl;
}

int main(){
    queue q(7);
    q.enqueue(8);
    q.enqueue(6);
    q.enqueue(4);

    q.display();
    cout << q.dequeue() << endl;
    q.display();


    return 0;
}
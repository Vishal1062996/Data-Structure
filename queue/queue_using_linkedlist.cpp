#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};

class queue{
    private:
    Node *front;
    Node *rear;
    public:
    queue(){
        front=rear=NULL;
    }

    void enqueue(int x);
    int dequeue();
    void display();
};

void queue::enqueue(int x){
    Node *p= new Node;
    p->data = x;
    p->next=NULL;
    if(front==NULL){
        front=p;
        rear=p;
    }
    else{
        
        rear->next=p;
        rear=p;
    }
}

int queue::dequeue(){
    int x=-1;
    if(front==NULL){
    }
    else{
        x=front->data;
        front = front->next;
    }
    return x;
}

void queue::display(){
    Node *p=front;
    while(p){
        cout << p->data << " ";
        p=p->next;
    }
    cout << endl;
}

int main(){
    queue qs;
    qs.enqueue(5);
    qs.enqueue(6);
    qs.enqueue(7);
    qs.enqueue(9);


    qs.display();

    cout << qs.dequeue()<<endl;

    qs.display();


    return 0;
}
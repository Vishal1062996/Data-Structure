#include<iostream>
using namespace std;

class node{
    public:
    node *prev;
    int data;
    node *next;
};

class Doublylinkedlist{
    private:
    node *first;
    public:
    Doublylinkedlist(){
        first = NULL;
    }
    Doublylinkedlist(int A[], int n);

    void display();
    int length();
};

Doublylinkedlist::Doublylinkedlist(int A[], int n){
    node *last, *t;
    first = new node;
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++){
        t = new node;
        t->prev = last;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Doublylinkedlist::display(){
    node *p = first;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Doublylinkedlist::length(){
    node *p = first;
    int c = 0;
    while(p){
        c++;
        p = p->next;
    }
    return c;
}

int main(){
    int A[] = {2,45,56,4,677};

    Doublylinkedlist d1(A,5);
    d1.display();
    cout << d1.length();
    
    return 0;
}
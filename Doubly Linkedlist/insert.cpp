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
    void insert(int x, int index);
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

void Doublylinkedlist::insert(int x, int index){
    node *p=first, *t;
    if(index < 0 || index > length()){
        return;
    }
    if(index==0){
        t = new node;
        t->data = x;
        t->prev = NULL;
        if(first == NULL){
            first = t;
            first->next = NULL;
        }
        else{
            t->next = first;
            first->prev = t;
            first = t;
        }
    }
    else{
        t = new node;
        t->data = x;
        for(int i=0; i<index-1; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
        t->prev = p;
    }
}

int main(){
    int A[] = {2,45,56,4,677};

    Doublylinkedlist d1(A,5);
    d1.display();
    d1.insert(5,8);
    d1.display();
    
    return 0;
}
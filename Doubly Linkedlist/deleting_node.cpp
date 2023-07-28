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
    int Delete(int index);
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

int Doublylinkedlist::Delete(int index){
    node *p, *q;
    int x;
    if(index<=0 || index>length()){
        return -1;
    }
    if(index == 1){
        p = first;
        x = first->data;
        if(first->next == NULL){
            delete first;
            first = NULL;
        }
        else{
            first = first->next;
            first->prev = NULL;
            delete p;
            p = NULL;
        }
    }
    else{
        p = first;
        for(int i=0; i<index-2; i++){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        if(q->next!=NULL){
        q->next->prev = p;}
        x = q->data;
        delete q;
        q=NULL;
    }
    return x;
}

int main(){
    int A[] = {2,45,56,4,677};

    Doublylinkedlist d1(A,5);
    d1.display();
    cout << d1.Delete(5) << endl;
    d1.display();
    
    return 0;
}
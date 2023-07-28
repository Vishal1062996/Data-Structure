#include<iostream>
using namespace std;

class node{
    public:
    node *prev;
    int data;
    node *next;
};

class circular_doubly{
    private:
    node *first;
    public:
    circular_doubly(){
        first = NULL;
    }
    circular_doubly(int A[], int n);

    void display();
    void insert(int index , int num);
    int Delete(int index);
    int length();
};

circular_doubly::circular_doubly(int A[], int n){
    node *last, *t;
    first = new node;
    first->data = A[0];
    first->prev = NULL;
    first->next = first;
    last = first;

    for(int i=1; i<n; i++){
        t = new node;
        t->data = A[i];
        t->prev = last;
        t->next = first;
        first->prev = t;
        last->next = t;
        last = t;
    }
}

void circular_doubly::display(){
    node *p = first;
    do{
        cout << p->data << " ";
        p = p->next;
    }while(p != first);
    cout << endl;
}

int circular_doubly::length(){
    node *p = first;
    int c=1;
    while(p->next!=first){
        c++;
        p=p->next;
    }
    return c;
}

void circular_doubly::insert(int index, int num){
    node *p,*t;
    if(index<0 || index>length()){
        return;
    }
    if(index==0){
        t = new node;
        t->data = num;
        if(first == NULL){
            first = t;
            first->prev=first;
            first->next = first;
        }
        else{
            t->next = first;
            t->prev = first->prev;
            first->prev->next = t;
            first->prev = t;
            first = t;
        }
    }
    else{
        p= first;
        t = new node;
        t->data = num;
        for(int i=0; i<index-1; i++){
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        p->next->prev = t;
        p->next = t;
    }
}

int circular_doubly::Delete(int index){
    node *t, *p;
    int x;
    if(index<1 || index>length()){
        return -1;
    }
    if(index==1){
        t=first;
        x = first->data;
        if(first->next = first){
            delete first;
            first = NULL;
        }
        else{
            p=first->prev;
            p->next = first->next;
            first->next->prev = p;
            first = first->next;
            delete t;
            t = NULL;
        }
    }
    else{
        p =first;
        t=first;
        for(int i=0; i<index-2; i++){
            p = p->next;
        }
        t = p->next;
        x = t->data;
        p->next = t->next;
        t->next->prev = p;
        delete t;
        t = NULL;
    }
    return x;
}

int main(){
    int A[] = {3,5,66,7,5,4};
    
    circular_doubly c1(A, 6);

    c1.display();
    cout << c1.Delete(1) << endl;
    // c1.insert(0,10);
    c1.display();

    return 0;
}
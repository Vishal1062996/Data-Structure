#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class Linkedlist{
    private:
    node *first;
    public:
    Linkedlist(){
        first = NULL;
    }
    Linkedlist(int A[], int n);
    // ~Linkedlist(){
    //     cout << "destructor is executed\n";
    // };

    void display();
    int length();
    int Delete(int index);
};

Linkedlist::Linkedlist(int A[], int n){
    node *last, *t;
    first = new node;
    first->data = A[0];
    first->next = first;
    last = first;

    for(int i=1; i<n; i++){
        t = new node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}


void Linkedlist::display(){
    node *p = first;
    do{
        cout << p->data << " ";
        p = p->next;
    }while(p != first);
    cout << endl;
}

int Linkedlist::length(){
    node *p = first;
    int len=0;
    do{
        len++;
        p = p->next;
    }while(p != first);
    return len;
}

int Linkedlist::Delete(int index){
    node *p, *q;
    int x;

    if(index<=0 || index>length()){
        return -1;
    }
    else if(index == 1){
        p = first;
        x = first->data;
        while(p->next!=first){
            p = p->next;
        }
        if(p == first){
            delete first;
            first = NULL;
        }
        else{
            q = first;
            first = first->next;
            delete q;
            q = NULL;
            p->next = first;
        }
    }
    else{
        p = first;
        for(int i=1; i<index-1; i++){
            p = p->next;
        }
        q = p->next;
        x = q->data;
        p->next = q->next;
        delete q;
        q=NULL;
    }
    return x;
}

int main(){
    int A[] = {3,5,5,6,4,3,7};
    Linkedlist l1(A,7);
    l1.display();
    cout << l1.Delete(8)<< endl;
    l1.display();


    return 0;
}
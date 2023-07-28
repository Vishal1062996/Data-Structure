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
    void Insert(int x, int pos);
    int length();
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
    int len=1;
    do{
        len++;
        p = p->next;
    }while(p != first);
    return len;
}

void Linkedlist::Insert(int num, int pos){
    node *p = first;
    node *t;
    if(pos<0 && pos>length()){
        return;
    }
    if(pos==0){
        t = new node;
        t->data = num;
        if(first = NULL){
            first = t;
            first->next = first;
        }
        else{
            while(p->next != first){
                p=p->next;
            }
        t->next = first;
        p->next = t;
        first = t;
        }
    }
    else{
        for(int i=0; i<pos-1; i++){
            p = p->next;
        }
        t = new node;
        t->data = num;
        t->next = p->next;
        p->next = t;
    }
}

int main(){
    int A[] = {3,5,5,6,4,3,7};
    Linkedlist l1(A,7);
    l1.display();
    l1.Insert(10,0);
    l1.display();


    return 0;
}
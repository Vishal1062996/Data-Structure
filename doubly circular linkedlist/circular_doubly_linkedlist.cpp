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
int main(){
    int A[] = {3,5,66,7,5,4};
    
    circular_doubly c1(A, 6);

    c1.display();
    return 0;
}
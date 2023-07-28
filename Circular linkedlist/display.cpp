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
    void Rdisplay(node *p);
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

// Linkedlist::~Linkedlist(){
//     node *p = first;
//     do{
//         first = first->next;
//         delete p;
//         p = first;
//     }while(first->next != first);

//     cout << "Destructor is executed\n";
// }

void Linkedlist::display(){
    node *p = first;
    do{
        cout << p->data << " ";
        p = p->next;
    }while(p != first);
    cout << endl;
}

void Linkedlist::Rdisplay(node *p){
    // node *p = first;
    static bool flag = false;
    if(p!=first || !flag){
        flag = true;
        cout << p->data << " ";
        Rdisplay(p->next);
    }
    flag = false;
}
int main(){
    int A[] = {3,5,5,6,4,3,7};
    Linkedlist l1(A,7);
    l1.display(l1);

    return 0;
}
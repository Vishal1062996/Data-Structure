#include<iostream>
#include<stack>
using namespace std;

void enqueue(stack <int> *s,int x){
    s->push(x);
}

int dequeue(stack <int> *s1, stack <int> *s2){
    int x=-1;
    if(s2->empty()){
        if(s1->empty()){
            return x;
        }
        else{
            while(!s1->empty()){
                s2->push(s1->top());
                s1->pop();
            }
        }
    }
    x=s2->top();
    s2->pop();
    return x;
}

void display(stack <int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main(){
    stack <int> s1;
    stack <int> s2;

    enqueue(&s1,5);
    enqueue(&s1,6);
    enqueue(&s1,7);
    enqueue(&s1,8);
    enqueue(&s1,9);

    display(s1);

    cout << dequeue(&s1,&s2) << endl;
    cout << dequeue(&s1,&s2) << endl;
    cout << dequeue(&s1,&s2) << endl;

    enqueue(&s1,11);
    enqueue(&s1,34);

    display(s1);

    cout << dequeue(&s1,&s2) << endl;
    cout << dequeue(&s1,&s2) << endl;
    cout << dequeue(&s1,&s2) << endl;


    return 0;
}
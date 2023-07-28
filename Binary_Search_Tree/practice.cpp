#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root=NULL;

void insert(int key){
    struct Node *t=root,*r=NULL;
    struct Node *p;

    if(root==NULL){
        p=new struct Node;
        p->data = key;
        p->lchild=p->rchild = NULL;
        root = p;
        return;
    }
    else{
        while(t){
            r=t;
            if(key < t->data) t=t->lchild;
            else if(key > t->data) t=t->rchild;
            else return;
        }
        p=new struct Node;
        p->data = key;
        p->lchild=p->rchild = NULL;

        if(key < r->data) r->lchild=p;
        else r->rchild=p;
    }
}

void inorder(struct Node *p){
    if(p){
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

int main(){
    struct Node *root=NULL;
    insert(5);
    insert(10);
    inorder(root);
    return 0;
}
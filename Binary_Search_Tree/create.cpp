#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *lchild, *rchild;
}*root=NULL;

void Insert(int key){
    struct Node *t=root, *p, *r=NULL;

    if(t==NULL){
        p=new struct Node;
        p->data=key;
        p->lchild = NULL;
        p->rchild = NULL;
        root=p;
        return;
    }
    else{
        while(t){
            r=t;
            if(key<t->data){
                t=t->lchild;
            }
            else if(key > t->data){
                t=t->rchild;
            }
        }
        p = new struct Node;
        p->data = key;
        p->lchild = p->rchild = NULL;

        if(key<r->data){
            r->lchild = p;
        }
        else{
            r->rchild = p;
        }
    }
}

void Inorder(struct Node *root){
    if(root){
        Inorder(root->lchild);
        cout << root->data << " ";
        Inorder(root->rchild);
    }
}

struct Node *Search(struct Node *root, int key){
    struct Node *p=root;
    while(p){
        if(key==p->data){
        return p;
        }
        else if(key<p->data){
            p=p->lchild;
        }
        else{
            p=p->rchild;
        }
    }
    return NULL;
}

int main(){
    struct Node *r=NULL;
    Insert(5);
    Insert(50);
    Insert(24);
    Insert(10);
    Insert(3);
    Inorder(root);
    // cout << endl;
    // r=Search(root, 55);

    // if(r!=NULL)cout << "Found" << endl;
    // else{
    //     cout << "Not found" << endl;
    // }

    return 0;
}
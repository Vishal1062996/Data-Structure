#include<iostream>
using namespace std;

class BST{
    private:
    int data;
    BST *rchild, *lchild;

    public:
    BST(){data = 0; rchild=NULL ; lchild=NULL;};
    BST(int n){data = n; rchild =NULL ; lchild = NULL;};

    BST* Insert(BST *root, int key);
    void Inorder(BST *root);
};

BST* BST::Insert(BST *root, int key){
    BST *t=root,*p,*r;
    if(t==NULL){
        p = new BST;
        p->lchild = p->rchild = NULL;
        p->data = key;
        return t;
    }
    
    while(t!=NULL){
        r=t;
        if(t->data == key){
        return NULL;
        }
        else if(t->data < key){
        t = t->rchild;
        }
        else{
            t = t->lchild;
        }
    }
    p = new BST;
    p->data = key;
    p->rchild = p->lchild = NULL;
    if(key > r->data){
        r->rchild = p;
    }
    else{
        r->lchild = p;
    }
}

void BST::Inorder(BST *t){
    if(t){
        Inorder(t->lchild);
        cout << t->data << " ";
        Inorder(t->rchild);
    }
    return;
}
int main(){
    BST b;
    BST *root=NULL;
    root = b.Insert(root, 25);
    b.Inorder(root);
    return 0;
}
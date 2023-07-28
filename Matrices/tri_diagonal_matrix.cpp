#include<iostream>
using namespace std;

class tri_diagonal{
    private:
    int n;
    int *A;
    public:
    tri_diagonal(){
        n=3;
        A=new int[3];
    }
    tri_diagonal(int m){
        n=m;
        A=new int[3*n-2];
    }
    ~tri_diagonal(){
        delete []A;
    }

    void display();
    void set(int r, int c, int x);
    int get(int r, int c);
};

void tri_diagonal::display(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i-j==1){
                cout << A[j] << " ";
            }
            if(i-j==0){
                cout << A[n-1+j] << " ";
            }
            if(i-j==-1){
                cout << A[2*n-1+i] << " ";
            }
            else{
                cout << "0" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void tri_diagonal::set(int r, int c, int x){
            if(r-c==1){
                A[c]=x;
            }
            if(r-c==0){
                A[n-1+c]=x;
            }
            if(r-c==-1){
                A[2*n-1+r]=x;
            }
}

int tri_diagonal::get(int r, int c){
    if(r-c==1){
        return A[c];
    }
    if(r-c==0){
        return A[n-1+c];
    }
    if(r-c==-1){
        return A[2*n-1+r];
    }
    else{
        return 0;
    }
}
int main(){
    int m;
    // cout << "Enter the dimension: ";
    cin >> m;

    tri_diagonal t(m);

    int x;
    // cout << "Enter the numbers: ";
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            cin >> x;
            t.set(i,j,x);
        }
    }
    t.display();

    
    return 0;
}
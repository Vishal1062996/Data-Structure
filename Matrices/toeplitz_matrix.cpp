#include<iostream>
using namespace std;

class toeplitz{
    private:
    int n;
    int *A;
    public:
    toeplitz(){
        n=2;
        A=new int[2];
    }
    toeplitz(int m){
        n=m;
        A=new int[2*n-1];
    }
    ~toeplitz(){
        delete []A;
    }

    void display();
    int get(int r,int c);
    void set(int r, int c, int x);
};

void toeplitz::set(int r,int c,int x){
    if(r<=c){
        A[c-r]=x;
    }
    if(r>c){
        A[n+r-c-1]=x;
    }
}

int toeplitz::get(int r,int c){
    if(r<=c){
        return A[c-r];
    }
    if(r>c){
        return A[n+r-c-1];
    }
    cout << endl;
}

void toeplitz::display(){
    for(int i=1;i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i<=j){
                cout << A[j-i] << " ";
            }
            if(i>j){
                cout << A[n+i-j-1] << " ";
            }
        }cout << endl;
    }cout << endl;
}

int main(){
    int n;
    cin >> n;

    int x;
    toeplitz t(n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> x;
            if(j==1 || i==1){
                t.set(i,j,x);
            }
        }
    }
    t.display();
    
    return 0;
}
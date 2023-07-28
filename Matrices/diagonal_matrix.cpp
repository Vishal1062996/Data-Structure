#include<iostream>
using namespace std;

class matrix{
    private:
    int *A;
    int n;
    public:
    matrix(){
        n=2;
        A=new int[2];
    }
    matrix(int m){
        n=m;
        A = new int[n];
    }
    ~matrix(){
    delete [] A;
    A = NULL;
}

    void set(int r, int c, int num);
    int get(int r, int c);
    void display();
};

void matrix::set(int r , int c, int num){
    if(r==c){
        A[r]=num;
    }
}

int matrix::get(int r, int c){
    if(r==c){
        return A[r];
    }
    else{
    return 0;}
}

void matrix::display(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                cout << A[i] << " ";
            }
            else{
                cout << "0" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    matrix m(5);
    m.set(0,0,1);
    m.set(1,1,2);
    m.set(2,2,3);
    m.set(3,3,4);
    m.set(4,4,5);
    // cout << m.get(1,1);
    m.display();
    return 0;
}
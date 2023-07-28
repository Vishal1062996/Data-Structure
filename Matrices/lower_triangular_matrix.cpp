#include<iostream>
using namespace std;

class matrix{
    private:
    int n;
    int *A;
    public:
    matrix(){
        n=3;
        A=new int[n];
    }
    matrix(int m){
        n=m;
        int x=m*(m-1)/2;
        A=new int[x];
    }
    ~matrix(){
        delete []A;
        A=NULL;
    }

    void display();
    void set(int r, int c, int num);
    int get(int r, int c);
};


void matrix::display(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>=j){
                cout << A[i*(i+1)/2 + j] << " ";
            }
            else{
                cout << "0" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void matrix::set(int r, int c, int num){
    int row_major = r*(r+1)/2 + c;
    if(r>=c){
        A[row_major]=num;
    }
}

int matrix::get(int r, int c){
    int row_major = r*(r+1)/2 + c;
    if(r>=c){
        return A[row_major];
    }
    else{
        return 0;
    }
}

int main(){
    int d;
    cout << "Enter the dimension: ";
    cin >> d;
    matrix m(d);
    int x;

    cout << "Enter the numbers: ";
    for(int i=0; i<d; i++){
        for(int j=0; j<d; j++){
            cin >> x;
            m.set(i,j,x);
        }
    }
    
    cout << m.get(0,0) << endl;
    m.display();
    
    return 0;
}
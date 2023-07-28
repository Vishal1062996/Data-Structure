#include<iostream>
using namespace std;

class symmetric{
    private:
    int n;
    int *A;
    public:
    symmetric(){
        n=2;
        A=new int[2];
    }
    symmetric(int m){
        n=m;
        A=new int[n*(n+1)/2];
    }
    ~symmetric(){
        delete []A;
    }

    void display();
    int get(int r, int c);
    void set(int r,int c, int x);
};

void symmetric::display(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i>=j){
            cout << A[i*(i+1)/2+j] << " ";
            }
            else{
            cout << A[j*(j+1)/2+i] << " ";   
            }
        }
        cout << endl;
    }
    cout << endl;
}

int symmetric::get(int r, int c){
    if(r>=c){
        return A[r*(r+1)/2+c];
    }
    else{
        return A[c*(c+1)/2+r];
    }
}

void symmetric::set(int r, int c, int x){
        A[r*(r+1)/2+c]=x;
}

int main(){
    int n;
    cout << "Enter the dimension: ";
    cin >> n;
    int x;

    symmetric s(n);

    cout << "Enter the number: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> x;
            if(i>=j){
            s.set(i,j,x);
            }
        }
    }
    s.display();
    return 0;
}
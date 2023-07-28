#include<iostream>
using namespace std;

class upper_triangle{
    private:
    int n;
    int *A;
    public:
    upper_triangle(){
        n=2;
        A=new int[2];
    }
    upper_triangle(int m){
        n=m;
        A=new int[m*(m+1)/2];
    }
    ~upper_triangle(){
        delete []A;
    }

    void display();
    void set(int r, int c, int num);
    int get(int r, int c);
};

void upper_triangle::display(){
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(j>=i){
                cout << A[n*(i-1)+((i-1)*(i-2)/2)+j-i] << " ";
            }
            else{
                cout << "0"<< " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void upper_triangle::set(int r, int c, int num){
    
    if(c>=r){
        int row_major = n*(r-1)+((r-1)*(r-2)/2)+c-r;
        A[row_major] = num;
    }
}

int upper_triangle::get(int r, int c){
    int row_major = n*(r-1)+((r-1)*(r-2)/2)+c-r;
    if(c>=r){
        return A[row_major];
    }
    else{
        return 0;
    }
}

int main(){
    int a;
    cout << "Enter the dimendsion: ";
    cin >> a;
    int x;

    upper_triangle u(a);
    
    cout << "Enter the number: ";
    for(int i=1; i<=a; i++){
        for(int j=1; j<=a; j++){
            cin >> x;
            if(j>=i){
            u.set(i,j,x);
            }
        }
    }
    u.display();
    
    return 0;
}
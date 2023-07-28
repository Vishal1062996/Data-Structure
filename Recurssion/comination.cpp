#include<iostream>
using namespace std;

long int fact(int n){
    if(n == 0 || n==1){
        return 1;
    }
    else{
        return fact(n-1)* n;
    }
}
long int combination(int n, int r){
    if(n<r)
        cout << "r cannot be greater than n";
    return fact(n)/(fact(r)*fact(n-r));
}

int main(){
    int n, r;
    cin >> n >> r;
    // cout << fact(n);
    cout << combination(n, r) ;
    return 0;
}
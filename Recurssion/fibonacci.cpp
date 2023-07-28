#include<iostream>
using namespace std;

// int fibo(int n){
//     int t0=0, t1=1, sum;
//     if(n==0 || n==1){
//         return n;
//     }
//     else{
//     for(int i=2; i<=n; i++){
//         sum = t0 + t1;
//         t0 = t1;
//         t1 = sum;
//         }
//     }
//     return sum;
// }

int fibo(int n){
    if(n == 0 || n==1){
        return n;
    }                             // time complexity of this function is 2**n;
    else{
        return fibo(n-2) + fibo(n-1);
    }
}

int main(){
    int n;
    cin >> n;
    cout << fibo(n);
    return 0;
}
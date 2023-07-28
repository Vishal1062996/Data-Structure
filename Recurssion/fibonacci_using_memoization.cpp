#include<iostream>
using namespace std;

int arr[1000];

int fibo(int n){
    if(n==0 || n==1){
        arr[n] = n;
        return n;
    }
    else{
        if(arr[n-2] == -1){
            arr[n-2] = fibo(n-2);
        }
        if(arr[n-1] == -1){
            arr[n-1] = fibo(n-1);
        }
        return fibo(n-2) + fibo(n-1);
    }
}
int main(){
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        arr[i] = -1;
    }
    
    cout << fibo(n) <<endl;
    return 0;
}
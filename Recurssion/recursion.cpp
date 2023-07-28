#include <iostream>
#include <cmath>     // abs ----> absolute value
#include <bits/stdc++.h>     // setprecision
using namespace std;
void digit (int x){
    if(x >0){
        digit(x-1);
        cout << x << " " ;
    }     
}

void digit1 (int x){
        
    if (x > 0){
        cout << x << " " ;
        return digit1(x-1);   // you can use this statement without return also
    }
}

int main (){
    int num1;
    cin >> num1;

    digit(num1);
    cout << endl;
    digit1(num1);
    return 0;
}
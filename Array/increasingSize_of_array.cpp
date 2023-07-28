#include<iostream>
using namespace std;

int main(){

    int *p = new int[5];
    for(int i=0; i<5; i++){
        cin >> p[i];
    }

    int *q = new int [10];

    for(int i=0; i<5; i++){
        q[i] = p[i];
    }
    
    p = q;
    delete [] p;
    q = NULL;

    cout << p[3] << endl;

    return 0;

}
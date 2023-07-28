#include<iostream>
using namespace std;

int main(){
    // int arr[3][4] = {{1,2,3,4}, {5,6,7,4}, {33,23,4,5}};   /* 2D array completely inside the stack */
    // int n,m;                                               
    // int arr[n][m];

    int *arr[3];
    arr[0] = new int [4];
    arr[1] = new int [4];    // 2D array partially in stack and heap;
    arr[2] = new int [4];

    int **p;
    p = new int* [3];
    p[0] = new int [4];    // 2D array completely inside the heap
    p[1] = new int [4];
    p[2] = new int [4];

    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
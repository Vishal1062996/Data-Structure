#include<iostream>
using namespace std;

struct Array{
    int *p;            //we are taking pointet because we want to create array in heap
    int size;
    int length;      
};

void display(struct Array A){
    for(int i=0; i<A.length; i++){
        cout << A.p[i] << " ";
    }
}

int main(){
    struct Array arr;
    cout << "Enter the size of the Array";
    cin >> arr.size ;
    cout << "Enter the length of the Array";
    cin >> arr.length;
    arr.p = new int [arr.size];

    for(int i=0; i<arr.length; i++){
        cin >> arr.p[i];
    }

    display(arr);
    return 0;
}
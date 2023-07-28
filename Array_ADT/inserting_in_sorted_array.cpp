#include<iostream>
using namespace std;

struct Array{
    int A[15];
    int size;
    int length;
};

void display(struct Array arr){
    for(int i=0; i<arr.length ; i++){
        cout << arr.A[i] << " ";
    }
}

void insert(struct Array *arr, int key){
    int len = (arr->length)-1;
    
    while(arr->A[len] > key){
        arr->A[len+1] = arr->A[len];
        len--;
    }
    arr->A[len+1] = key;
    arr->length++;
}


int main(){
    struct Array arr = {{1,2,4,5,6}, 15, 5};
    
    insert(&arr, 3);
    display(arr);
    return 0;
}
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

void reverse(struct Array *arr){
    int *B = new int(arr->length);
    for(int i=0; i<arr->length ; i++){
        B[i] = arr->A[(arr->length)-1-i];
    }
    for(int i=0; i<arr->length; i++){
        arr->A[i] = B[i];
    }
}

void reverse1(struct Array *arr){
    for(int i=0, j=(arr->length)-1 ; i<j ; i++,j--){
        int temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

int main(){
    struct Array arr = {{1,2,34,5,6}, 15, 5};
    
    // reverse(&arr);
    reverse1(&arr);
    display(arr);
    return 0;
}
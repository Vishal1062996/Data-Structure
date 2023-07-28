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

void left_rotate(struct Array *arr){
    int temp =arr->A[0];                   // same code is for left shifting just we 
    for(int i=1; i<arr->length; i++){      // don't have to save the last element
        arr->A[i-1] = arr->A[i];
    }
    arr->A[(arr->length)-1] = temp;
}


int main(){
    struct Array arr = {{1,2,34,5,6}, 15, 5};
    
    left_rotate(&arr);
    display(arr);
    
    
    return 0;
}
#include<iostream>
using namespace std;

struct Array{
    int A[15];
    int size;
    int length;
};

void display(struct Array arr){
    for(int i=0; i<arr.length; i++){
        cout << arr.A[i] << " ";
    }
}

void append(struct Array *Arr, int num){
    if(Arr->length < Arr->size){
    Arr->A[Arr->length] = num;
    Arr->length++;
    }
}

void insert(struct Array *arr,int num, int pos){
    if(pos>=0 && pos<arr->length){
    for(int i=arr->length; i>pos; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[pos] = num;
    arr->length++;
    }
}


int main(){
    struct Array arr = {{1,2,34,5,6}, 15, 5};
    insert(&arr, 15, 3);
    append(&arr, 20);
    display(arr);
    
    return 0;
}
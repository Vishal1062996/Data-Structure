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

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void negative_shift(struct Array *arr){
    int i=0;
    int j=(arr->length)-1;
    while(i<j){
       while(arr->A[i]<0)i++;
       while(arr->A[j]>=0)j--;
       if(i<j)swap(&arr->A[i], &arr->A[j]);
    }
}


int main(){
    struct Array arr = {{1,2,-4,5,-6}, 15, 5};
    
    negative_shift(&arr);
    display(arr);
    return 0;
}
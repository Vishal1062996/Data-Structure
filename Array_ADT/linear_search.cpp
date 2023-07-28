#include<iostream>
using namespace std;

struct Array{
    int A[15];
    int size;
    int length;
};

int linearSearch(struct Array *arr,int key){
    for(int i=0; i<arr->length; i++){
        if(arr->A[i] == key){
            int temp = arr->A[i-1];   //method 1
            arr->A[i-1] = arr->A[i];
            arr->A[i] = temp;
            // swap(arr.A[i], arr.A[0]);    //method 2
            return i;
        }
    }
    return -1;
}


int main(){
    struct Array arr = {{1,2,34,5,6}, 15, 5};
    
    cout << linearSearch(&arr,5);
    
    
    return 0;
}
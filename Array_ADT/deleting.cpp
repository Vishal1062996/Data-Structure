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
// bool check(struct Array arr, int num){
//     for (int  i = 0; i < arr.length; i++)
//     {
//         if(num == arr.A[i]){
//             return true;
//         }
//     }  
// }

void del(struct Array *arr, int index){
    // arr->A[index] = 0;
    if(index>=0 && index<=arr->length){
    for(int i=index; i<arr->length - 1; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
    }
}

int main(){
    struct Array arr = {{1,2,34,5,6}, 15, 5};

    del(&arr,2);
    display(arr);
    
    return 0;
}
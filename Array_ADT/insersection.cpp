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


struct Array *Intersection(struct Array *arr1, struct Array *arr2){
    int m = arr1->length;
    int n = arr2->length;
    int len = arr1->length + arr2->length;
    struct Array *c = new struct Array [len];
    int i=0,j=0,k=0;

    while(i<m && j<n){
        if(arr1->A[i] < arr2->A[j]){
            i++;
        }
        else if(arr1->A[i] == arr2->A[j]){
            c->A[k] = arr1->A[i];
            i++; j++; k++;
        }
        else{
            j++;
        }
    }
    c->length = k;
    c->size = 100;
        
    return c;
}


int main(){
    struct Array arr1 = {{1,2,4,5,6}, 15, 5};
    struct Array arr2 = {{4,5,6,7,9}, 15, 5};
    struct Array *c;
    c = Intersection(&arr1, &arr2);
    
    display(*c);
    
    return 0;
}
#include<iostream>
using namespace std;

struct Array{
    int A[15];
    int size;
    int length;
};

int BinarySearch(struct Array arr, int key){
    int low = 0;
    int high = arr.length - 1;
    int mid ;          
    
    while(low <= high){
        mid = (low + high)/2;
        if(arr.A[mid] == key){
            return mid;
        }
        else if(key > arr.A[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int RBinarySearch(struct Array arr, int l, int h, int key){
    int mid = (l + h)/2;

    if(arr.A[mid] == key){
        return mid;
    }
    else if (key > arr.A[mid]){
        return RBinarySearch(arr,mid+1,h,key);
    }
    else{
        return RBinarySearch(arr,l,mid-1,key);
    }
}

int main(){
    struct Array arr = {{1,2,3,4,5}, 15, 5};
    
    cout << RBinarySearch(arr,0,5,3);
    
    
    return 0;
}
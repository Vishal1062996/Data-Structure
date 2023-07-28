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

string sort(struct Array arr){
    for(int i=0; i<arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1]){
            return "unsorted";
        }
    }
    return "sorted";
}

int main(){
    struct Array arr = {{1,3,4,5,6}, 15, 5};
    
    // if(sort ){
    //     cout << "It is a sorted array" <<endl;
    // }
    // else{
    //     cout << "It is an unsorted array"<< endl;
    // }
    cout << sort(arr);
    // display(arr);
    return 0;
}
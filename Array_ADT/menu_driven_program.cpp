#include<iostream>
using namespace std;

struct Array{
    int *A;
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

void del(struct Array *arr, int index){
    // arr->A[index] = 0;
    if(index>=0 && index<=arr->length){
    for(int i=index; i<arr->length - 1; i++){
        arr->A[i] = arr->A[i+1];
    }
    arr->length--;
    }
}

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

int main(){
    struct Array arr;
    cout << "Enter the size of the Array: \n";
    cin >> arr.size;
    arr.A = new int [arr.size];
    int ch, num, index;

    do{
    cout << "menu\n";
    cout << "1. Insert\n";
    cout << "2. Append\n";
    cout << "3. Delete\n";
    cout << "4. Search\n";
    cout << "5. Display\n";
    cout << "6. Exit\n";

    cout << "Enter the number to select : \n";
    cin >> ch;

    switch(ch){
        case 1: 
        cout << "Enter the number and Index : \n";
        cin >> num >> index;
        insert(&arr,num,index);
        break;

        case 2:
        cout << "Enter the number : \n";
        cin >> num;
        append(&arr, num);
        break;

        case 3:
        cout << "Enter the index : \n";
        cin >> index;
        del(&arr, index);
        break;

        case 4:
        cout << "Enter the number : \n";
        cin >> num;
        cout << BinarySearch(arr, num);
        break;

        case 5:
        display(arr);
        break;

        default:
        break;
    }   
    }while(ch<6);
    return 0;
}
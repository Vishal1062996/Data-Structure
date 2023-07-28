#include<iostream>
using namespace std;

class Array{
    private:
    int *A;
    int size;
    int length;

    public:
    Array(){
        size = 10;
        length = 0;
        A = new int [size];
    }
    Array(int sz){
        size = sz;
        length =0;
        A = new int [sz];
    }
    ~Array(){
        delete []A;
    }

    void display();
    void insert(int num, int index);
    void append(int num);
    int BinarySearch(int key);
    void del(int index);
    
};

void Array::display(){
    for(int i=0; i<length; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}

void Array::append(int num){
    if(length < size){
    A[length] = num;
    length++;
    }
}

void Array::insert(int num, int pos){
    if(pos>=0 && pos<length){
    for(int i=length; i>pos; i--){
        A[i] = A[i-1];
    }
    A[pos] = num;
    length++;
    }
}

void Array::del(int index){
    // arr->A[index] = 0;
    if(index>=0 && index<=length){
    for(int i=index; i<length - 1; i++){
        A[i] = A[i+1];
    }
    length--;
    }
}

int Array::BinarySearch(int key){
    int low = 0;
    int high = length - 1;
    int mid ;
    
    while(low <= high){
        mid = (low + high)/2;
        if(A[mid] == key){
            return mid;
        }
        else if(key > A[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    Array *arr;
    int sz;
    cout << "Enter the size of the Array: \n";
    cin >> sz;
    arr = new Array [sz];
   
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
        arr->insert(num,index);
        break;

        case 2:
        cout << "Enter the number : \n";
        cin >> num;
        arr->append(num);
        break;

        case 3:
        cout << "Enter the index : \n";
        cin >> index;
        arr->del(index);
        break;

        case 4:
        cout << "Enter the number : \n";
        cin >> num;
        cout << arr->BinarySearch(num);
        break;

        case 5:
        arr->display();
        break;

        default:
        break;
    }   
    }while(ch<6);
    return 0;
}
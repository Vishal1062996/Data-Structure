#include<iostream>
using namespace std;

// void missing(int arr[]){
//     int diff = arr[0] ;
//     int arrSize = sizeof(arr)/sizeof(int);
//     for(int i=0; i<arrSize; i++){
//         if(arr[i]-i != diff){                 //error is coming
//             while(diff < arr[i]- i){
//                 cout << diff+i;
//                 diff++;
//             }
//         }
//     }

// }

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int low = arr[0];
    int high;
    
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            high = arr[i];
        }
        else{
            high = arr[i+1];
        }
    }
    cout << high;

    int H[high];
    for(int i=0; i<n; i++){
        H[arr[i]]++;
    }
    for(int i=low; i<high; i++){
        if(H[i] == 0){
            cout << i << " ";
        }
    }

    return 0;
}
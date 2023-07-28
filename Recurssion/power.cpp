#include<iostream>
using namespace std;

// int power (int m, int n){
//     if (n == 0)
//         return 1;
//     return m * power (m, n-1);
// }

int power1(int m, int n){
    if(n == 0){
        return 1;
    }
    if (n % 2 == 0)
        return power1(m*m, n/2);
    return m * power1(m*m , (n-1)/2);
}


// int power (int m, int n){                  // Both the functions are equivalent
//     if (n == 0){
//         return 1;
//     }
//     else {
//         return m * power (m , n-1);
//     }
// }

int main(){
    int m, n;
    cin >> m >> n;
    // cout << power (m, n);
    cout << power1 (m, n);
    return 0;
}
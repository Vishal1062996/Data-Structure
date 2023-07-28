#include<iostream>
using namespace std;

struct myArray{
   int total_size;
   int used_size;
   int * p;
}; 

int createArray(struct myArray * x, int tsize, int usize){
    (*x).total_size = tsize;
    (*x).used_size = usize;
    (*x).p = 
}


int main(){
    struct myArray marks;
    createArray(&marks);

    return 0;
}
#include <iostream>
#include <string>

using namespace std;

int* func(){
    int array[2];
    array[0] = 0;
    array[1] = 1;
    int*intPtr = &array[0]; 
    return intPtr;
}

int main(){

    int * array;
    array = func();
    std::cout << *(int+1); 
}


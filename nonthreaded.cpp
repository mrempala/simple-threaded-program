//A non threaded version for benchmarking
#include <time.h>
#include <stdlib.h>
#include <iostream>

const int ARRAY_SIZE = 1000000;

int main(){
    int intArr[ARRAY_SIZE];
    srand(1);
    
    for(int i=0; i<ARRAY_SIZE; i++){
        intArr[i] = rand() % 1000;
    }
    
    //Start Clock


    int sum = 0;
    for(int i=0; i<ARRAY_SIZE; i++){
        sum += intArr[i];
    }
    std::cout<<"The sum is: "<<sum<<std::endl;

    //End Clock

    
    return 0;
}

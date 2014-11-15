//A non threaded version for benchmarking
#include <time.h>
#include <stdlib.h>
#include <iostream>

const int ARRAY_SIZE = 100000;

//Super naive, meant to be computationaly expensive
bool isPrime(int inNum){
    if(inNum <= 3)
        return true;
        
    //inNum/2 would be slightly less naive
    for(int i=2; i<inNum-1; i++){
        if(inNum % i == 0){
            return false;
        }
    }
    
    return true;
}

int main(){
    int intArray[ARRAY_SIZE];
    srand(1);
    
    for(int i=0; i<ARRAY_SIZE; i++){
         intArray[i] = 1000000 + 5 * i;
    }
    
    //Start Clock


    int sum = 0;
    for(int i=0; i<ARRAY_SIZE; i++){
        if(isPrime(intArray[i])){
            sum += intArray[i];
        }
    }
    std::cout<<"The sum is: "<<sum<<std::endl;

    //End Clock


    
    return 0;
}

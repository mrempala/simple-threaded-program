//A non threaded version for benchmarking
#include <time.h>
#include <stdlib.h>
#include <iostream>

const int ARRAY_SIZE = 1000000;

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
    int intArr[ARRAY_SIZE];
    srand(1);
    
    for(int i=0; i<ARRAY_SIZE; i++){
        intArr[i] = rand() % 1000;
    }
    
    //Start Clock
    clock_t progTime = clock();

    int sum = 0;
    for(int i=0; i<ARRAY_SIZE; i++){
        if(isPrime(intArr[i])){
            sum += intArr[i];
        }
    }
    std::cout<<"The sum is: "<<sum<<std::endl;

    //End Clock
    progTime = clock() - progTime;
    std::cout<<"Time: "<<((float)progTime)/CLOCKS_PER_SEC<<" seconds"<<std::endl;
    
    return 0;
}

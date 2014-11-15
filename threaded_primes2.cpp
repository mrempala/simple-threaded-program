//100,000 sized array with numbers from 1,000,000-1,500,000
#include <thread>
#include <time.h>
#include <iostream>
#include <stdlib.h>

const int NUM_THREADS = 8;
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

void summationThread(const int intArr[], int startIndex, int endIndex, int *result){
    *result = 0;
    //std::cout<<"Hello "<<startIndex<<std::endl;
    for(int i=startIndex; i<=endIndex; i++){
        if(isPrime(intArr[i])){
            *result += intArr[i];
        }
    }
    //std::cout<<"Bye   "<<startIndex<<std::endl;
}

int main(){
    int intArray[ARRAY_SIZE];
    srand(1);
    
    for(int i=0; i<ARRAY_SIZE; i++){
        intArray[i] = 1000000 + 5 * i;
    }
    
    //Start Clock
    
    std::thread threadArr[NUM_THREADS];
    int intermediateSums[NUM_THREADS];
    for(int i=0; i<NUM_THREADS; i++){
        intermediateSums[i] = 0;
    }
 
    for(int i=0; i<NUM_THREADS; i++){
        int startIndex = i * (ARRAY_SIZE / NUM_THREADS);
        int endIndex = (i+1) * (ARRAY_SIZE / NUM_THREADS) - 1;
        if(i==NUM_THREADS-1){
            //In case array size is not evenly divisible by num threads
            endIndex = ARRAY_SIZE - 1;
        }
        
        threadArr[i] = std::thread(summationThread, intArray, startIndex, endIndex, &(intermediateSums[i]) );
    }
    
    for(int i=0; i<NUM_THREADS; i++){
        threadArr[i].join();
    }

    int completeSum = 0;
    for(int i=0; i<NUM_THREADS; i++){
        completeSum += intermediateSums[i];
    }
    std::cout<<"The sum is: "<<completeSum<<std::endl;

    //End Clock

    return 0;
}

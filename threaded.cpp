//A simple program that uses threads to sum up a 1 million int array on 8 threads
//Assumes that the resulting sum can fit in a 32-bit int (max ~2 billion)
//Requires C++11 for std::thread
//Note: ask Evan about passing by reference instead of ptr in func with & in main
#include <thread>
#include <time.h>
#include <iostream>
#include <stdlib.h>

const int NUM_THREADS = 8;
const int ARRAY_SIZE = 1000000;

void summationThread(const int intArr[], int startIndex, int endIndex, int *result){
    *result = 0;
    for(int i=startIndex; i<=endIndex; i++){
        *result += intArr[i];
    }
}

int main(){
    int intArray[ARRAY_SIZE];
    srand(1);
    
    for(int i=0; i<ARRAY_SIZE; i++){
        intArray[i] = rand() % 1000;
    }
    
    //Start Clock
    clock_t progTime = clock();
    
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
    progTime = clock() - progTime;
    std::cout<<"Time: "<<((float)progTime)/CLOCKS_PER_SEC<<" seconds"<<std::endl;
    
    return 0;
}

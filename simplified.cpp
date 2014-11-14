//Same program, but simplified a bit by removing unneccesary checks
#include <thread>
#include <time.h>
#include <iostream>
#include <stdlib.h>

const int NUM_THREADS = 8;
const int ARRAY_SIZE = 1000000;

void summationThread(const int intArr[], int startIndex, int endIndex, int *result){
    *result = 0;
    for(int i=startIndex; i<=endIndex; i++)
        *result += intArr[i];
}

int main(){
    std::thread threadArr[NUM_THREADS];
    int intermediateSums[NUM_THREADS];
    int intArray[ARRAY_SIZE];
    
    for(int i=0; i<ARRAY_SIZE; i++)
        intArray[i] = rand() % 1000;
    
    //Start Clock
    clock_t progTime = clock();
 
    for(int i=0; i<NUM_THREADS; i++){
        int startIndex = i * (ARRAY_SIZE / NUM_THREADS);
        int endIndex = (i+1) * (ARRAY_SIZE / NUM_THREADS) - 1;
        threadArr[i] = std::thread(summationThread, intArray, startIndex, endIndex, &(intermediateSums[i]) );
    }
    
    int completeSum = 0;
    for(int i=0; i<NUM_THREADS; i++){
        threadArr[i].join();
        completeSum += intermediateSums[i];
    }
    
    std::cout<<"The sum is: "<<completeSum<<std::endl;

    //End Clock
    progTime = clock() - progTime;
    std::cout<<"Time: "<<((float)progTime)/CLOCKS_PER_SEC<<" seconds"<<std::endl;
    
    return 0;
}

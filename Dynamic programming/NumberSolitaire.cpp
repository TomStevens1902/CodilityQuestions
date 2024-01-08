//https://app.codility.com/demo/results/trainingKKN787-P3A/

#include <limits.h>


int solution(vector<int>& A) {
    const int N = A.size();

    //create an array for every square
    //this will be used to store the 
    //max sum that square using the previous
    vector<int> MaxSums(N, INT_MIN);
    //We start from 0
    MaxSums[0] = A[0];
    //loop through the rest of the array and populates
    //the max sum for each square working backwards
    for (int i{ 1 }; i < N; i++) {
        for (int dice{ 1 }; dice <= 6; dice++) {
            //disregard anything before the start as it
            //does not exist (we're working backwards to find max sum
            //for i)
            if (dice > i) { break; }
            //max sum is calculated by adding the previous sums
            //we use the max of the previous sums for each square
            MaxSums[i] = std::max(MaxSums[i], A[i] + MaxSums[i - dice]);
        }
    }
    return MaxSums[N - 1];
}
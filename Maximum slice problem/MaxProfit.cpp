//optimized = https://app.codility.com/demo/results/trainingU8SNF7-G44/
int solution(vector<int>& A) {
    //if array empty return no profit
    size_t n = A.size();
    if (n == 0)
        return 0;
    
    int max_profit = 0;
    int profit_sum = 0;
    for (size_t i = 1; i < n; i++) {
        //calculates the sum of how much profit is made as each day passes.
        profit_sum = max(0, profit_sum + A[i] - A[i - 1]);
        //saves the max profit if the sum for that day is greater then the stored max profit.
        max_profit = max(max_profit, profit_sum);
    }
    //returns 0 if no profit is made as max profit is initialised with 0
    return max_profit;
}

/*
--------
*/

//unoptimized = https://app.codility.com/demo/results/trainingPSDX9E-392/
int solution::unoptimized(vector<int> &A) {
    long maxProfit{0};
    int length = A.size();
    for (int i{0}; i<length; i++) {
        for (int j{i+1}; j<length; j++) {
            if(A[j] >= A[i]){
                long profit = A[j] - A[i];
                maxProfit = std::max(maxProfit,profit);
            }
        }
    }
    return maxProfit;

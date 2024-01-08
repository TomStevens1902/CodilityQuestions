//https://app.codility.com/demo/results/trainingCRSPY2-DPK/

#include <numeric>

int solution(vector<int>& A) {
    const int N = A.size();
    if (N == 0)
        return 0;

    //find max value in the array and set array to positive values
    int MaxVal = 0;
    for (int i = 0; i < N; i++) {
        A[i] = abs(A[i]);
        MaxVal = max(MaxVal, A[i]);
    }

    //calculate the sum of the elements within the array
    const int Sum = std::accumulate(A.begin(), A.end(), 0);

    //creates a list to populate with either 1 or -1
    vector<int> dp(Sum + 1, 0);


    dp[0] = 1;
    //loop through given array
    for (int j = 0; j < N; j++)
        //loop backwards from the sum of the array to 0
        for (int i = Sum; i > -1; i--)
            if (dp[i] == 1 and i + A[j] <= Sum)
                dp[i + A[j]] = 1;

    int result = Sum;
    for (int i = 0; i < Sum / 2 + 1; i++)
        if (dp[i] == 1) {
            result = min(result, Sum - 2 * i);
        }
    return result;
}
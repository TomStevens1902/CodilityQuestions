//https://app.codility.com/demo/results/training9SDMBG-95K/

int findHeighestCounter(vector<int>& Counters) {
    int heighestValue{ 0 };

    //loop through counters
    int length = Counters.size();
    for (int i{ 0 }; i < length; i++) {
        if (i == 0) {
            heighestValue = Counters[i];
            continue;
        }
        //find the heighest value counter
        if (Counters[i] > heighestValue) {
            heighestValue = Counters[i];
        }
    }
    return heighestValue;
}

vector<int> solution(int N, vector<int>& A) {
    //setup list of counters
    vector<int>counters(N, 0);
    //if A[K] (k is index) = X
    //loop through operations
    int length = A.size();
    for (int i{ 0 }; i < length; i++) {
        //check for increase
        if (A[i] >= 1 && A[i] <= N) {
            counters[(A[i] - 1)]++;
            //check for max counter
        }
        else if (A[i] == (N + 1)) {
            //find the max value of counters
            int maxValue = findHeighestCounter(counters);
            //set max value for every counter
            for (auto& counter : counters) {
                counter = maxValue;
            }
        }
        else {
            continue;
        }
    }
    return counters;
}
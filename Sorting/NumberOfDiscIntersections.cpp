//https://app.codility.com/demo/results/trainingYPWW45-CWS/

int solution(vector<int>& A) {
    int count = 0;
    int n = A.size();

    for (int i{ 0 }; i < n; i++) {
        for (int j{ 0 }; j < n; j++) {
            if ((j - i) <= ((long)A[i] + (long)A[j])) {
                count++;
            }
        }
    }

    count = count - (n * (n + 1) / 2);
    if (count > 1e7) {
        return -1;
    }

    return count;
}
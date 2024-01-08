//https://app.codility.com/demo/results/trainingXKPHAC-EAF/

int solution(int A, int B, int K) {
    int count{ 0 };
    for (int i{ A }; i <= B; i++) {
        if (i % K == 0) {
            count++;
        }
    }
    return count;
}

//the 100% approach#
//int solution(int A, int B, int K)
//{
//    return (B / K - A / K + !(A % K));
//}
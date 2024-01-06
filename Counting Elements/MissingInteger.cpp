//https://app.codility.com/demo/results/trainingFYZQGT-KNA/

int solution(vector<int>& A) {
    //"N is an integer within the range [1..100,000]" 
    const int N = 1000001;

    //create a list to store valid ints to check through
    vector<bool> validInts(N, false);

    //loop through given array and populate valid ints
    for (auto& i : A) {
        //"returns the smallest positive integer (greater than 0)"
        //disregard anything below 0
        if (i > 0) {
            validInts[i] = true;
        }
    }

    //loop through and find the first false interger (this represents the smallest interger)
    for (int i{ 1 }; i < N; i++) {
        if (validInts[i] == false) {
            return i;
        }
    }

    //if no interger above 0 is found 1 is returned
    //as "each element of array A is an integer within the range [−1,000,000..1,000,000]."
    return 1;
}
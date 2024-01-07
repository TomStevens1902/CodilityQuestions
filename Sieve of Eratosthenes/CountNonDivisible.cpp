//https://app.codility.com/demo/results/trainingT3ZZHM-82W/

vector<int> solution(vector<int>& A) {
    //create an array to add the non divisor count to
    vector<int> B{};
    //for each element go through and try and divide by the other elements
    for (const auto& i : A) {
        int count{ 0 };
        for (const auto& j : A) {
            //if there is a remainder we have found a non divisor
            if ((i % j) != 0) { count++; }
        }
        //add divisor to the stack building the array of answers
        B.push_back(count);
    }
    return B;
}
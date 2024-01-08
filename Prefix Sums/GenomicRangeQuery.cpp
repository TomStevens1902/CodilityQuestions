//https://app.codility.com/demo/results/trainingWRC96Y-4EY/

int findImpactValue(char Nucleotide) {
    switch (Nucleotide)
    {
    case 'A':
        return 1;
    case 'C':
        return 2;
    case 'G':
        return 3;
    case 'T':
        return 4;
    default:
        return 0;
    }

}

vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {
    vector<int> M{};
    int length{ P.size() };
    for (int i{ 0 }; i < length; i++) {
        int minValue{ -1 };
        for (int j{ P[i] }; j <= Q[i]; j++) {
            if (minValue == -1) {
                minValue = findImpactValue(S[j]);
            }
            minValue = std::min(minValue, findImpactValue(S[j]));
        }
        M.push_back(minValue);
    }
    return M;
}
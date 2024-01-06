//https://app.codility.com/demo/results/trainingDBVFZK-9U9/
#include <vector>
using namespace std;

struct PlankStruct {
    int start;
    int stop;
};

int solution(vector<int>& A, vector<int>& B, vector<int>& C) {
    const int N = A.size();
    const int M = C.size();
    vector<PlankStruct> remaining(N);
    vector<bool> nails(M, false);

    // create plank struct
    for (int i = 0; i < N; i++) {
        remaining[i].start = A[i];
        remaining[i].stop = B[i];
    }

    int minimum = -1;

    // go through each nail, done once list is empty
    vector<PlankStruct> planks;

    for (int j = 0; j < M; j++) {
        if (nails[C[j]]) {
            continue;
        }

        nails[C[j]] = true;
        planks = remaining;
        remaining.clear();

        for (int i = 0; i < (int)planks.size(); i++) {
            if ((C[j] < planks[i].start) || (C[j] > planks[i].stop)) {
                // Nail doesn't touch this plank 
                remaining.push_back(planks[i]);
            }
            else {
                // Nail is in plank, remove it from consideration
                // by not adding it to remaining
            }
        }

        // Nothing remains!  This was the final nail.
        if (remaining.size() == 0) {
            minimum = j + 1;
            break;
        }
    }

    return minimum;
}



// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <iterator>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());

    int N = A.size();
    int min = A[0];
    int max = A[N-1];
    cout << "max " << max << " min " << min << '\n';

    copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    // initial count
    int init = 1;
    //for (auto it = A.begin(); it != A.end(); ++it) {
    for (int i = 1; i < N; ++i) {
        if (A[i] - A[0] >= N) {
            break;
        }
        ++init;
    }
    cout << "init " << init << endl;

    for (int i = N; i < max; ++i) {
        if (A[i-N]
                }


                copy(A.begin(), A.end(), ostream_iterator<int>(cout, " "));
                return 0;
                }

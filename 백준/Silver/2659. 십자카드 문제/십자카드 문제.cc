#include <bits/stdc++.h>
using namespace std;

int main() {


    vector<int> A;
    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            for (int c = 1; c <= 9; c++) {
                for (int d = 1; d <= 9; d++) {

                    int t = 1000 * a + 100 * b + 10 * c + d;
                    t = min(t, 1000 * b + 100 * c + 10 * d + a);
                    t = min(t, 1000 * c + 100 * d + 10 * a + b);
                    t = min(t, 1000 * d + 100 * a + 10 * b + c);

                    A.push_back(t);
                }
            }
        }
    }

    sort(A.begin(), A.end());
    int a, b, c, d;
    cin >> a >> b >> c >> d;


    int t = 1000 * a + 100 * b + 10 * c + d;
    t = min(t, 1000 * b + 100 * c + 10 * d + a);
    t = min(t, 1000 * c + 100 * d + 10 * a + b);
    t = min(t, 1000 * d + 100 * a + 10 * b + c);

    int ind = 0, cnt = 1;
    while(ind < A.size() && A[ind] != t) {
        if (ind == 0 || A[ind - 1] != A[ind]) cnt++;
        ind++;
    }

    cout << cnt;
}
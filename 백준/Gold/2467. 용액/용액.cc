#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    sort(A.begin(), A.end());

    int curr = 2000000001;
    int l = 0, r = n - 1;
    int al = -1, ar = -1;
    while (l < r) {
        int test = abs(A[l] + A[r]);
        if (test < curr) {
            al = l;
            ar = r;
            curr = test;
        }

        if (abs(A[l]) > abs(A[r])) l++;
        else r--;
    }

    cout << A[al] << ' ' << A[ar];
}
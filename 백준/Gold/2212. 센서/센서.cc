#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;


    vector<int> A(n);
    for (auto& i : A) cin >> i;

    

    if (k >= n) {
        cout << 0;
        return 0;
    }

    vector<int> B;
    sort(A.begin(), A.end());

    int ans = A[n - 1] - A[0];
    for (int i = 1; i < n; i++) {
        B.push_back(A[i] - A[i - 1]);
    }

    sort(B.rbegin(), B.rend());
    for (int i = 0; i < k - 1; i++) {
        ans -= B[i];
    }
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n), sA(n);
    for (auto& i : A) cin >> i;
    sA[0] = A[0];
    for (int i = 1; i < n; i++) sA[i] = sA[i - 1] + A[i];

    int mv = *max_element(A.begin() + 1, A.end() - 1);

    int ans = sA[n - 1] - A[n - 1] - A[0] + mv;
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, sA[n - 1] - A[n-1] + sA[i - 1] - A[i]);
        ans = max(ans, sA[n - 1] - A[0] + sA[n - 1] - sA[i] - A[i]);
    }

    cout << ans;
}
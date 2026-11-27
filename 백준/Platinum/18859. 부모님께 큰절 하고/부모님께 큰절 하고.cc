#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A)cin >> i;
    sort(A.begin(), A.end());

    vector<int> B = { A[0], A[1] }, C = { A[0] };
    for (int i = 2; i < n; i++) {
        if (A[i] - B.back() == A[1] - A[0]) B.push_back(A[i]);
        else C.push_back(A[i]);
    }

    if (A[1] == A[0]) {
        cout << "No";
        return;
    }

    bool ok = 1;
    for (int i = 1; i < C.size(); i++) {
        if (C[1] - C[0] != C[i] - C[i - 1]) ok = 0;
    }
    if (C.size() > 1 && C[1] - C[0] == 0) ok = 0;

    if (ok) {
        cout << "Yes";
        return;
    }

    C.push_back(B.back());
    sort(C.begin(), C.end());

    ok = 1;
    for (int i = 2; i < C.size(); i++) {
        if (C[i] - C[i - 1] != C[1] - C[0]) ok = 0;
    }

    if (ok) cout << "Yes";
    else cout << "No";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
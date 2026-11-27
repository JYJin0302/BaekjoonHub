#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n), B;
    for (auto& i : A) cin >> i;
    sort(A.begin(), A.end());

    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (A[i] != A[i - 1]) {
            B.push_back(cnt);
            cnt = 1;
        }
        else cnt++;
    }
    B.push_back(cnt);

    int sz = B.size();
    for (int i = sz - 1; i >= 0; i--) {
        if (B[i] % 2 == 1) {
            cout << "koosaga";
            return 0;
        }
    }
    cout << "cubelover";

}
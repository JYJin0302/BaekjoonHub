#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int x; cin >> x;

    vector<bool> ck(n);
    ck[x] = 1;

    int cnt = n + 1;
    while (cnt--) {
        for (int i = 0; i < n; i++) {
            if (A[i] != -1 && ck[A[i]]) {
                ck[i] = 1;
            }
        }
    }

    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        if (A[i] != -1 && !ck[i]) B[A[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!ck[i] && B[i] == 0) ans++;
    }
    cout << ans;
}
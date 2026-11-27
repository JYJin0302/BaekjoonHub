#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> A(n + 1), B(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    B[1] = A[1];
    for (int i = 2; i <= n; i++) {
        B[i] = A[i] - B[i - 1];
    }

    int ans = n, l = 1;
    for (int i = 2; i <= n; i++) {
        ll curr = A[i];
        bool ok = 0;
        for (int j = i-1; j >= l; j--) {
            curr = A[j] - curr;
            if (curr == 0) ok = 1;
            else if (curr < 0) break;
        }
        if (ok) {
            ans--;
            l = i + 1;
        }
    }

    cout << ans;
}
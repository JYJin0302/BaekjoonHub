#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second



void solve() {

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> A(n), B(n);
    for (auto& i : A) cin >> i;
    for (auto& i : B) cin >> i;

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (A[i] == B[i]) continue;
        if (a == b) {
            cout << "NO\n";
            return;
        }
        int dif = A[i] - B[i];
        int d2 = a - b;
        if (dif * d2 > 0) {
            cout << "NO\n";
            return;
        }

        if (abs(dif) % (abs(d2))) {
            cout << "NO\n";
            return;
        }

        ans[i] = abs(dif) / abs(d2);

    }
    cout << "YES\n";
    for (auto f : ans) cout << f << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
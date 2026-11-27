#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n = 9;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int tot = 0;
    for (auto f : A) tot += f;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] + A[j] == tot - 100) {
                for (int f = 0; f < n; f++) {
                    if (f != i && f != j) cout << A[f] << '\n';
                }
                return;
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int cnt[111];

void solve() {

    int n, p;
    cin >> n >> p;

    int v = n;
    cnt[n] = 1;
    int ord = 1;
    while (1) {
        v = v * n % p;
        ord++;
        if (cnt[v]) {
            cout << ord - cnt[v];
            return;
        }
        cnt[v] = ord;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
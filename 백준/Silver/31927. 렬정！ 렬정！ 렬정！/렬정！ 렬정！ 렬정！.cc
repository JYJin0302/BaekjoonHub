#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    cout << n / 2 << '\n';
    int val = 1e6;
    int l = 0, r = n - 1;
    while (l < r) {

        if (l) {
            val = min(val, A[l - 1] - A[l]);
            val = min(val, A[r] - A[r + 1]);
        }

        A[l] += val;
        A[r] -= val;

        for (auto f : A) cout << f << ' ';
        cout << '\n';
        l++, r--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
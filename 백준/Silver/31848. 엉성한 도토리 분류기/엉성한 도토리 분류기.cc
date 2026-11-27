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

    vector<int> res(n);
    res[0] = A[0];
    for (int i = 1; i < n; i++) {
        res[i] = max(res[i - 1], i + A[i]);
    }
    vector<pair<int, int>> tmp;
    for (int i = 0; i < n; i++) {
        if (!i || res[i] != res[i - 1]) tmp.push_back(mp(res[i], i));
    }


    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        auto ix = lower_bound(all(tmp), mp(x, -1));
        cout << (*ix).second + 1 << ' ';

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
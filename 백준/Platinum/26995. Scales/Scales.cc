#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, c;
vector<int> A;

int ans = 0;
void getAns(int ix, int cur = c) {
    if (ix == n) {
        ans = max(ans, c - cur);
        return;
    }

    if (ix + 1 < n) {
        if (A[ix] + A[ix + 1] <= cur) {
            getAns(ix + 1, cur - A[ix]);
            return;
        }
    }

    if (A[ix] <= cur) getAns(ix + 1, cur - A[ix]);
    getAns(ix + 1, cur);
}

void solve() {
    cin >> n >> c;
    
    A = vector<int> (n);
    for (auto& i : A) cin >> i;
    sort(A.rbegin(), A.rend());
    getAns(0);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
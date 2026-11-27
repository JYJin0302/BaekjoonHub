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

    vector<int> B;
    int ix = 0;
    while (ix < n) {
        int nx = ix;
        while (nx < n && A[ix] == A[nx]) nx++;
        B.push_back(nx - ix);
        ix = nx;
    }

    int ans = B[0];
    for (int i = 1; i < B.size(); i++) {
        ans = max(ans, B[i] + B[i - 1]);
    }
    cout << ans << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}

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

    vector<char> A(n);
    for (auto& i : A) cin >> i;

    int l = 0, r = n - 1;
    string ans;
    while (l <= r) {

        int sl = l, sr = r;
        while (l <= r && A[l] == A[r]) {
            l++, r--;
        }


        if (l > r || A[l] < A[r]) {
            ans += A[sl];
            l = sl + 1;
            r = sr;
        }
        else {
            ans += A[sr];
            l = sl;
            r = sr - 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i % 80 == 79) cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
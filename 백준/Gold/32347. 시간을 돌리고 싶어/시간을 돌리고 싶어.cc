#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<int> nx(n);
    for (int i = n - 1; i >= 0; i--) {
        if (A[i] == 1) nx[i] = i;
        else nx[i] = nx[i + 1];
    }

    int l = 1, r = n;
    int ans = n;
    while (l <= r) {
        int md = (l + r) >> 1;
        int cnt = k;
        int pos = n-1;
        while (pos && cnt) {
            pos = nx[pos];
            pos -= md;
            pos = max(pos, 0);
            cnt--;
        }

        if (pos == 0) {
            ans = md;
            r = md - 1;
        }
        else  l = md + 1;

    }
    cout << ans << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}
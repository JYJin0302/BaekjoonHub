#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

bool chk[101][101];

void solve() {

    int n;
    cin >> n;

    vector<int> A(n + 1);
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (A[i]) continue;
        cnt++;
        for (int j = i * 2; j <= n; j += i) A[j] = 1;
    }

    vector<pair<int, int>> ans;
    ans.push_back(mp(1, 1));
    for (int i = n; i >= 3; i--) {
        if (A[i]) {
            if (i % 2 == 0) {
                ans.push_back(mp(2, i));
            }
            else {
                ans.push_back(mp(1, i));
                ans.push_back(mp(2, i));
            }
        }
        else {
            ans.push_back(mp(1, i));
        }
    }
    cout << ans.size() << '\n';
    for (auto [a, b] : ans) cout << a << ' ' << b << '\n';

    //for (auto [a, b] : ans) {
    //    if (a == 1) {
    //        for (int i = 1; i <= n; i++) {
    //            if (gcd(b, i) == 1) chk[b][i] = 1, chk[i][b] = 1;
    //        }
    //    }
    //    else {
    //        for (int i = 1; i <= n; i++) {
    //            if (gcd(b, i) != 1) chk[b][i] = 1, chk[i][b] = 1;
    //        }
    //    }
    //}

    //for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= n; j++) {
    //        if (i == j) chk[i][j] = 1;
    //        cout << chk[i][j];
    //    }
    //    cout << '\n';
    //}

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
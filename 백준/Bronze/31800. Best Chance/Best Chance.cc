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
    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(mp(x, i));
    }

   
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
    }

    vector<int> ans(n);
    sort(all(A));

    for (int i = 0; i < n; i++) {
        int ix = A[i].y;
        if (i == n - 1) {
            ans[ix] = A[i].x - A[i - 1].x;
        }
        else {
            ans[ix] = A[i].x - A[n - 1].x;
        }
    }

    for (auto f : ans) cout << f << ' ';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
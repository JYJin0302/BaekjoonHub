#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int ans[2020][2020];

void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;
    vector<pair<int, int>> B;
    for (int i = 0; i < n; i++) {
        B.push_back(mp(A[i], i));
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) {
        sort(all(B));
        int t = B[n - 1].y;

        for (int j = n - 2; B[n-1].x && j >= i; j--) {
            if (B[j].x) {
                B[j].x--;
                ans[t][B[j].y] = ans[B[j].y][t] = 1;
                B[n - 1].x--;
            }
        }

        if (B[n - 1].x) ok = 0;
    }
    if (!ok) cout << -1;
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
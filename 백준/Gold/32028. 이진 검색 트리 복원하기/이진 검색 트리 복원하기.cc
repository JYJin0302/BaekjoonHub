#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

#define NO {cout << -1; exit(0);}

int A[202020];
int H[202020];
vector<pair<int, int>> D[202020];

int idx[202020];

int L[202020], R[202020];

int cnt = 0;
void go(int v, int h = 0, int lv = -2e9 - 10, int rv = 2e9 + 10) {
    cnt++;
    if (idx[h + 1] < D[h + 1].size()) {
        auto&[a,b] = D[h + 1][idx[h + 1]];
        if (lv < a && a < A[v]) {
            // go left
            L[v] = b;
            idx[h + 1]++;
            go(b, h + 1, lv, A[v]);
        }
    }

    if (idx[h + 1] < D[h + 1].size()) {
        auto& [a, b] = D[h + 1][idx[h + 1]];
        if (A[v] < a && a < rv) {
            // go right
            R[v] = b;
            idx[h + 1]++;
            go(b, h + 1, A[v], rv);
        }
    }


}

void solve() {

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, h;
        cin >> a >> h;
        D[h].push_back(mp(a, i));
        A[i] = a;
        H[i] = h;
    }

    for (int i = 1; i <= n; i++) sort(all(D[i]));

    if (D[1].size() != 1) {
        NO
    }

    memset(L, -1, sizeof L);
    memset(R, -1, sizeof R);
    int r = D[1][0].y;
    go(r, 1);

    if (cnt != n) {
        NO;
    }
    for (int i = 1; i <= n; i++) cout << L[i] << ' ' << R[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
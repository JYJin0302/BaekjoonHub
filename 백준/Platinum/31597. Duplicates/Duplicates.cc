#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int A[101][101];

void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> row, col;
    for (int i = 0; i < n; i++) {
        vector<int> cnt(n + 1);
        bool ok = 0;
        for (int j = 0; j < n; j++) {
            cnt[A[i][j]]++;
            if (cnt[A[i][j]] == 2) ok = 1;
        }
        if (!ok) row.push_back(i);

        cnt = vector<int>(n + 1);
        ok = 0;
        for (int j = 0; j < n; j++) {
            cnt[A[j][i]]++;
            if (cnt[A[j][i]] == 2) ok = 1;
        }
        if (!ok) col.push_back(i);
    }

    vector<pair<pair<int, int>, int>> ans;
    int sC = col.size(), sR = row.size();
    for (int i = 0; i < min(sC, sR); i++) {
        int v = A[row[i]][col[i]];
        v = v % n + 1;
        ans.push_back(mp(mp(row[i], col[i]), v));
        A[row[i]][col[i]] = v;
    }

    for (int i = sR; i < sC; i++) {
        // col
        int c = col[i];
        int v = A[0][c];
        for (int j = 0; j < n; j++) {
            if (A[0][j] != v) {
                v = A[0][j];
                break;
            }
        }
        if (v == A[0][c]) v = v % n + 1;
        A[0][c] = v;
        ans.push_back(mp(mp(0, c), v));
    }

    for (int i = sC; i < sR; i++) {
        // row
        int r = row[i];
        int v = A[r][0];
        for (int j = 0; j < n; j++) {
            if (A[j][0] != v) {
                v = A[j][0];
                break;
            }
        }
        if (v == A[r][0]) v = v % n + 1;
        A[r][0] = v;
        ans.push_back(mp(mp(r, 0), v));
    }

    cout << ans.size() << '\n';
    for (auto f : ans) {
        auto& [a, b] = f.first;
        cout << a + 1 << ' ' << b + 1 << ' ' << f.second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
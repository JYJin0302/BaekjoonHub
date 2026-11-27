#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()


int A[5][5];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}
set<int> ans;

void go(int i, int j, int val = 0, int cnt = 0) {
    if (cnt == 6) {
        ans.insert(val);
        return;
    }

    for (int f = 0; f < 4; f++) {
        int ni = i + dx[f];
        int nj = j + dy[f];
        if (inGrid(ni, nj)) {
            go(ni, nj, val * 10 + A[ni][nj], cnt + 1);
        }
    }
}
void solve() {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            go(i, j);
        }
    }
    cout << ans.size();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
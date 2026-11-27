#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

char G[50][50];
int n;
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}
int dx[] = { -1,-1, -1, 0, 1, 1,1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1};


void solve() {
 cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == '.') continue;

            for (int d = 0; d < 8; d++) {
                int ni = i;
                int nj = j;

                bool ok = 1;
                for (int f = 0; f < 2; f++) {
                    ni += dx[d];
                    nj += dy[d];

                    if (inGrid(ni, nj) && G[ni][nj] == G[i][j]) {}
                    else ok = 0;
                }

                if (ok) {
                    cout << G[i][j];
                    return;
                }
            }

        }
    }

    cout << "ongoing";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
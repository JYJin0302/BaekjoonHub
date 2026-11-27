#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };
bool inGrid(int x, int y) {
    return x >= 0 && x <= m && y >= 0 && y <= m;
}

void solve() {

    cin >> m >> n;

    int x = 0, y = 0, dir = 0;
    bool ok = 1;
    while (n--) {
        string s;
        int d;
        cin >> s >> d;
        
        if (s[0] == 'T') {
            if (d == 0) dir = (dir + 3) % 4;
            else dir = (dir + 1) % 4;
        }
        else {
            x += dx[dir] * d;
            y += dy[dir] * d;

            if (!inGrid(x, y)) ok = 0;
        }
    }

    if (ok) cout << x << ' ' << y << '\n';
    else cout << -1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
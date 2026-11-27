#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dx[] = { 1, 0 };
int dy[] = { 0, 1 };
int U[505050];
int D[505050];
int L[505050];
int R[505050];
void update(int x, int y) {
    L[x] = min(L[x], y);
    R[x] = max(R[x], y);
    U[y] = min(U[y], x);
    D[y] = max(D[y], x);
}

int solve() {
    int n, m;
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;
    if (s1[0] == 'D') swap(s1, s2);

    // initialize
    for (int i = 1; i <= n; i++) {
        L[i] = m + 1;
        R[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        U[i] = n + 1;
        D[i] = 0;
    }

    int sz = n + m;
    vector<pair<int, int>> pU, pD;


    int cx = 1, cy = 1, dir = 1;
    pU.push_back(mp(1, 1));
    update(1, 1);
    for (int i = 1; i < sz; i++) {
        if (s1[i] != s1[i - 1]) {
            dir = 1 - dir;
        }
        cx += dx[dir], cy += dy[dir];
        pU.push_back(mp(cx, cy));
       // cout << cx << ' ' << cy << " | ";
        update(cx, cy);
        if (cx + cy == sz) break;
    }
    //cout << '\n';
    cx = 1, cy = 1, dir = 0;
    pD.push_back(mp(1, 1));
    for (int i = 1; i < sz; i++) {
        if (s2[i] != s2[i - 1]) {
            dir = 1 - dir;
        }
        cx += dx[dir], cy += dy[dir];
        pD.push_back(mp(cx, cy));
       // cout << cx << ' ' << cy << " | ";
        update(cx, cy);
        if (cx + cy == sz) break;
    }
   // cout << '\n';

    int val = 0;
    cx = n, cy = m, dir = 0;
   // cout << "Route U : ";
    for (int i = sz - 2; i; i--) {
        if (s1[i] != s1[i + 1]) {
            dir = 1 - dir;
        }

        cx -= dx[dir];
        cy -= dy[dir];
        if (dir) val++;
        else val--;

        int dd = D[cy] - cx;
        val = max(-dd, val);
        int rr = R[cx] - cy;
        val = min(val, rr);

       // cout << val << ' ';
    }
   // cout << '\n';

    int val2 = val;
    val = 0;
    cx = n, cy = m, dir = 1;
    //cout << "Route D: ";
    for (int i = sz - 2; i; i--) {
        if (s2[i] != s2[i + 1]) {
            dir = 1 - dir;
        }

        cx -= dx[dir];
        cy -= dy[dir];
        if (dir) val++;
        else val--;

        int dd = D[cy] - cx;
        val = max(-dd, val);
        int rr = R[cx] - cy;
        val = min(val, rr);
       // cout << val << ' ';
        
    }
    //cout << '\n';

    if (val != val2) {
        exit(-1);
    }
    return val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int tot = 0;
    while (t--) {
        tot += solve();
    }

    if (tot > 0) cout << "First\n";
    else cout << "Second\n";
}
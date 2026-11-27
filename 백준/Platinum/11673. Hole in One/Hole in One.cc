#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

#define x first
#define y second

int n;
pair<int, int> L[10], R[10];
pair<int, int> e;


int getVal(vector<int> tmp) {
    vector<pair<int, int>> tt;
    for (int i = 0; i < n; i++) if (tmp[i] != 0) tt.push_back(mp(tmp[i], i));

    sort(tt.begin(), tt.end());

    vector<int> b;
    for (auto f : tt) b.push_back(f.second);
    

   /* cout << "\n----------------GETval: ";
    for (auto f : b) cout << f << ' '; 
    cout << " | ";*/

    pair<int, int> dir = e;

    for (int f = b.size() - 1; f >= 0; f--) {
        if (L[b[f]].x == R[b[f]].x) {
            dir.x = 2 * L[b[f]].x - dir.x;
        }
        else {
            dir.y = 2 * L[b[f]].y - dir.y;
        }
    }

   // cout << dir.x << ' ' << dir.y << '\n';

    vector<pair<int, int>> tL(n+1), tR(n+1);
    for (int i = 0; i < n; i++) {
        tL[i] = L[i];
        tR[i] = R[i];
    }
    tL[n] = tR[n] = e;

    vector<int> useable(n + 1, -1);
    for (auto f : b) useable[f] = 1;
    useable[n] = 1;

    int ix = 0;
    double pv = 0;

    while (ix <= b.size()) {

       /* cout << "go: wall #" << ix + 1 << '\n';

        cout << "Current: \n";
        for (int f = 0; f < n; f++) cout << tL[f].first << ' ' << tL[f].second << " <-> " << tR[f].first << ' ' << tR[f].second << '\n';
        cout << "ENDcr\n";*/
        // line : 0, 0 -> dir.x, dir.y

        vector<pair<double, int>> conn;

        for (int j = 0; j < n; j++) {
            if (useable[j] == 0) continue;

            // check if line[j] is conneced with line 

            if (tL[j].x == tR[j].x) {
                if (dir.x != 0 ) {

                    bool ok = 0;
                    if (0 <= tL[j].x && tL[j].x <= dir.x) ok = 1;
                    if (dir.x <= tL[j].x && tL[j].x <= 0) ok = 1;

                    if (!ok) continue;

                    double pos = 1.0 * tL[j].x / dir.x * dir.y;

                    if (tL[j].y <= pos + 1e-7 && pos - 1e-7 <= tR[j].y) {
                        double tval = abs(pos) + abs(tL[j].x);

                        if (tval > pv) conn.push_back(mp(tval, j));
                    }
                }
            }
            else {

                if (dir.y != 0) {
                    double pos = 1.0 * tL[j].y / dir.y * dir.x;

                    bool ok = 0;
                    if (0 <= tL[j].y && tL[j].y <= dir.y) ok = 1;
                    if (dir.y <= tL[j].y && tL[j].y <= 0) ok = 1;

                    if (!ok) continue;

                    if (tL[j].x <= pos + 1e-7 && pos - 1e-7 <= tR[j].x) {
                        double tval = abs(pos) + abs(tL[j].y);
                        
                        if (tval > pv) conn.push_back(mp(tval, j));
                    }
                }
            }
        }

        sort(conn.begin(), conn.end());


        if (conn.empty()) break;

        int ansi = conn[0].second;

        //cout << "Wall found: " << ansi << ' ' << conn[0].first << '\n';

        if (ansi == n) break;
        if (useable[ansi] == -1 || ansi != b[ix]) {
            //cout << "wrong wall\n";
            return -1;
        }
        useable[ansi] = 0;
        pv = conn[0].first;
        ix++;

        for (int j = 0; j <= n; j++) {
            if (tL[ansi].x == tR[ansi].x) {
                tL[j].x = 2 * tL[ansi].x - tL[j].x;
                tR[j].x = 2 * tL[ansi].x - tR[j].x;

                if (tL[j].x >= tR[j].x) swap(tL[j].x, tR[j].x);
            }
            else {
                tL[j].y = 2 * tL[ansi].y - tL[j].y;
                tR[j].y = 2 * tL[ansi].y - tR[j].y;

                if (tL[j].y >= tR[j].y) swap(tL[j].y, tR[j].y);
            }
        }

    }

    if (ix != b.size()) return -1;
    return ix;


}

void solve() {

    cin >> n;
    cin >> e.x >> e.y;
    for (int i = 0; i < n; i++) {
        cin >> L[i].x >> L[i].y >> R[i].x >> R[i].y;

        if (L[i].x > R[i].x) swap(L[i].x, R[i].x);
        if (L[i].y > R[i].y) swap(L[i].y, R[i].y);

        if (L[i].x != R[i].x && L[i].y != R[i].y) {
            cout << "impossible\n";
            assert(0);
            return;
        }

    }

    int ans = -1;
    for (int i = 0; i <= n; i++) {

        vector<int> tmp(n);
        for (int j = 0; j < i; j++) tmp[n - i + j] = j + 1;

        do {
            int res = getVal(tmp);
            ans = max(ans, res);
            //cout << "Res: " << res << '\n';
        } while (next_permutation(tmp.begin(), tmp.end()));
    }

    if (ans == -1) cout << "impossible\n";
    else cout << ans;

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
}
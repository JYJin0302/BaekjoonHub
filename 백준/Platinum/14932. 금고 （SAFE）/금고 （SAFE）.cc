#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int nxt[1010101];
int topo[1010101];
bool vis[1010101];
void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string s;
            cin >> s;

            int ni = i, nj = j;
            
            int d = 0;
            char c = '?';

            for (auto f : s) {
                if (f >= '0' && f <= '9') {
                    d = d * 10 + f - '0';
                }
                else c = f;
            }

            if (c == 'U') {
                ni -= d;
            }
            else if (c == 'D') {
                ni += d;
            }
            else if (c == 'R') {
                nj += d;
            }
            else {
                nj -= d;
            }

            int u = i * n + j;
            int v = ni * n + nj;
            nxt[u] = v;
            topo[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n * n; i++) {
        if (topo[i] == 0) q.push(i);
    }

    int st = 0, ss = 0;
    if (!q.empty()) st = ss = q.front();

    int cnt = 0;
    while (!vis[st]) {
        vis[st] = 1;
        cnt++;
        st = nxt[st];
    }

    if (cnt == n * n) {
        if (q.empty()) cout << "THIEF LOVE IT!";
        else {
            cout << ss / n + 1 << ' ' << ss % n + 1;
        }
    }
    else cout << "TOO SAFE";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
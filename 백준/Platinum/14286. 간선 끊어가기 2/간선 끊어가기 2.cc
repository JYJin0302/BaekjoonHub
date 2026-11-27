#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

/*
0 : source
1 ~ n*m : 각 점
n*m+1~ n*m*2 : 복사본
n*m*2 + 1:  sink

*/

vector<int> adj[505];

int c[505][505];
int f[505][505];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b, w;
        cin >> a >> b >> w;

        adj[a].push_back(b);
        adj[b].push_back(a);

        c[a][b] = w;
        c[b][a] = w;
    }

    int s, e;
    cin >> s >> e;

    int ans = 0;
    while (1) {

        vector<int> from(n + 1, -1);
        from[s] = 0;

        queue<int> q;
        q.push(s);
        while (!q.empty()) {

            int a = q.front();
            q.pop();

            for (auto b : adj[a]) {
                if (from[b] == -1 && c[a][b] - f[a][b] > 0) {
                    from[b] = a;
                    q.push(b);
                }
            }
        }

        if (from[e] == -1) break;

        int mf = 500;
        int tx = e;
        while (tx != s) {
            int nx = from[tx];
            mf = min(mf, c[nx][tx] - f[nx][tx]);
            tx = nx;
        }
        tx = e;
        while (tx != s) {
            int nx = from[tx];
            f[nx][tx] += mf;
            f[tx][nx] -= mf;
            tx = nx;
        }

        ans += mf;

    }
    cout << ans;
}
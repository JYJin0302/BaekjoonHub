#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

/*
0 : source
1 - n : 사람
n+1 ~ n+d: 음식
n+d+1: sink

*/

int src, snk;

int f[333][333];
int c[333][333];

vector<int> adj[333];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, d;
    cin >> n >> k >> d;

    src = 0;
    snk = n + d + 1;

    for (int i = 1; i <= n; i++) {
        c[0][i] = k;
        adj[0].push_back(i);
        adj[i].push_back(0);
    }
    for (int i = 1; i <= d; i++) {
        c[n + i][snk] = 1;
        adj[n + i].push_back(snk);
    }

    for (int i = 1; i <= d; i++) {
        int x;
        cin >> x;

        c[n+i][snk] = x;
    }

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        while (a--) {
            int x;
            cin >> x;

            c[i][n + x] = 1;
            adj[i].push_back(n + x);
            adj[n + x].push_back(i);
        }
    }

    int ans = 0;
    while (1) {

        //cout << "Go flow\n";
        vector<int> from(snk+10, -1);
        from[0] = 0;

        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int a = q.front();
            q.pop();

            for (auto o : adj[a])
            {   
                if (from[o] == -1 && c[a][o] - f[a][o] > 0) {
                    from[o] = a;
                    q.push(o);
                }
            }
        }

        /*cout << "Res\n";
        for (int i = 0; i <= snk; i++) cout << from[i] << ' ';
        cout << '\n';*/


        if (from[snk] == -1) break;

        int mf = 10000;
        int tx = snk;
        while (tx) {
            int nx = from[tx];
            mf = min(mf, c[nx][tx] - f[nx][tx]);
            tx = nx;
        }

        tx = snk;
        while (tx) {
            int nx = from[tx];
            f[nx][tx] += mf;
            f[tx][nx] -= mf;
            tx = nx;
        }


        ans += mf;
        //cout << "ADd: " << mf << '\n';
    }
    cout << ans;

}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> pcnt(n + 1);
    vector<vector<int>> spt(22, vector<int>(n+1));
    vector<vector<ll>> ssum(22, vector<ll>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            pcnt[j]++;
        }
    }
    vector<int> topo(n);
    topo[0]++;
    for (int i = 1; i < n; i++) {
        int nx = (i + pcnt[i]) % n;
        topo[nx]++;
        spt[0][i] = nx;
        ssum[0][i] = nx;
    }

    for (int i = 1; i < 22; i++) {
        for (int j = 1; j < n; j++) {
            spt[i][j] = spt[i - 1][spt[i - 1][j]];
            ssum[i][j] = ssum[i - 1][j] + ssum[i - 1][spt[i - 1][j]];
        }
    }

    vector<int> cycleSize(n, -1);
    queue<int> q;
    for (int i = 0; i < n; i++) if (topo[i] == 0) q.push(i);
    while (!q.empty()) {

        int a = q.front();
        q.pop();
        cycleSize[a] = 0;

        int na = spt[0][a];
        topo[na]--;
        if (topo[na] == 0) q.push(na);
    }

    for (int i = 0; i < n; i++) {
        if (cycleSize[i] == -1) {
            int cnt = 1;
            int ix = spt[0][i];
            while (ix != i) {
                cnt++;
                ix = spt[0][ix];
            }

            cycleSize[i] = cnt;
            ix = spt[0][i];
            while (ix != i) {
                cycleSize[ix] = cnt;
                ix = spt[0][ix];
            }
        }
    }

    ll ansSum = 1e15, ansi = -1;
    for (int i = 0; i < n; i++) {

        // check valid
        bool ok = 1;
        if (cycleSize[i] > 0) {
            if (cycleSize[i] < k) ok = 0;
        }
        else {
            int ti = i;
            int tcnt = 1;
            for (int j = 21; j >= 0; j--) {
                int nx = spt[j][ti];
                if (cycleSize[nx] == 0) {
                    ti = nx;
                    tcnt += 1 << j;
                }
            }
            ti = spt[0][ti];
            tcnt += cycleSize[ti];

            if (tcnt < k) ok = 0;
        }

        if (!ok) continue;

        ll tans = i;
        int ti = i;
        for (int j = 0; j < 21; j++) {
            if ((k - 1) & (1 << j)) {
                tans += ssum[j][ti];
                ti = spt[j][ti];
            }
        }

        if (tans < ansSum) {
            ansSum = tans;
            ansi = i;
        }
    }

    if (ansi == -1) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < k; i++) {
        cout << ansi << ' ';
        ansi = spt[0][ansi];
    }
}
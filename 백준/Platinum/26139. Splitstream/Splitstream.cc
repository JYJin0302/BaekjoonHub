
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sz[200101];

ll fromL[200101], fromR[200101];

ll solve(ll g, ll k) {

    //cout <<"Go:"<< g <<' ' <<k <<'\n';
    if (k > sz[g] || k <= 0) return -1;
    if (g == 1) return k;

    if (fromL[g] == -1 || fromR[g] == -1) {

        // split

        ll ng = g, nk = k;
        if (fromL[g] != -1) {
            ng = fromL[g];
            nk = k * 2 - 1;
        }
        else {
            ng = fromR[g];
            nk = k * 2;
        }

        return solve(ng, nk);
    }
    else {

        // merge

        ll szL = sz[fromL[g]];
        ll szR = sz[fromR[g]];

        ll ng = g, nk = k;
        if (k <= 2 * min(szL, szR)) {

            if (k & 1) {
                ng = fromL[g];
                nk = (k + 1) / 2;
            }
            else {
                ng = fromR[g];
                nk = k / 2;
            }
        }
        else {
            k -= 2 * min(szL, szR);

            if (szL > szR) {
                ng = fromL[g];
                nk = szR + k;
            }
            else {
                ng = fromR[g];
                nk = szL + k;
            }

        }
        return solve(ng, nk);

    }

}

struct D {
    char c;
    int x, y, z;

    D() : c(' '), x(0), y(0), z(0) {}
    D(char _c, int _x, int _y, int _z) : c(_c), x(_x), y(_y), z(_z) {}
};

vector<int> adj[210101];
D inp[10101];
int topo[10100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(fromL, -1, sizeof(fromL));
    memset(fromR, -1, sizeof(fromR));

    ll m, n, q;
    cin >> m >> n >> q;    

    sz[1] = m;
    for (int i = 0; i < n; i++) {

        char c;
        cin >> c;

        int x, y, z;
        cin >> x >> y >> z;

        inp[i] = { c, x, y, z };

        if (c == 'S') {
            adj[x].push_back(i);
            topo[i]++;
        }
        else {
            topo[i] += 2;
            adj[x].push_back(i);
            adj[y].push_back(i);
        }

    }


    queue<int> tq;

    for (auto f : adj[1]) {
        topo[f]--;
        if (topo[f] == 0) tq.push(f);
    }

    while (!tq.empty()) {

        int a = tq.front();
        tq.pop();

        char c;
        int x, y, z;

        c = inp[a].c;
        x = inp[a].x;
        y = inp[a].y;
        z = inp[a].z;

        if (c == 'S') {

            int sr = sz[x] / 2;
            int sl = sz[x] - sr;
            sz[y] = sl;
            sz[z] = sr;

            fromL[y] = x;
            fromR[z] = x;

            for (auto f : adj[y]) {
                topo[f]--;
                if (topo[f] == 0) tq.push(f);
            }
            for (auto f : adj[z]) {
                topo[f]--;
                if (topo[f] == 0) tq.push(f);
            }
        }
        else {
            sz[z] = sz[x] + sz[y];
            fromL[z] = x;
            fromR[z] = y;

            for (auto f : adj[z]) {
                topo[f]--;
                if (topo[f] == 0) tq.push(f);
            }
        }
    }


    while (q--) {

        ll a, b;
        cin >> a >> b;

        ll res = solve(a, b);

        if (res == -1)cout << "none\n";
        else cout << res << '\n';

    }

}

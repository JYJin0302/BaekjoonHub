#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define no {cout << "impossible\n"; return;}

vector<int> adj[202020];
vector<pair<int, int>> adj2[404040];
int st[202020];

void solve() {

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') st[i + 1] = 0;
        else if (s[i] == 'G') st[i + 1] = 1;
        else st[i + 1] = 2;
    }

    for (int i = 1; i <= m; i++) {
        int t;
        cin >> t;
        while (t--) {
            int x;
            cin >> x;
            adj[x].push_back(i);
        }
    }

    vector<int> val(m + 1, -1);
    for (int i = 1; i <= n; i++) {
        int sz = adj[i].size();
        int u = 0, v = 0;
        if (sz == 0) {
            if (st[i]) no;
        }
        else if (sz == 1) {
            u = adj[i][0];
            if (val[u] == -1 || val[u] == (3 - st[i]) % 3) val[u] = (3 - st[i]) % 3;
            else no;
        }
        else {
            u = adj[i][0];
            v = adj[i][1];
            adj2[u].push_back(mp(v, st[i]));
            adj2[v].push_back(mp(u, st[i]));
            // cout << "EDG: " << u << ' ' << v << '\n';
        }
    }
    int ans = 0;
    queue<int> q;
    for (int i = 1; i <= m; i++) {
        if (val[i] != -1) q.push(i);
    }
    while (!q.empty()) {
        int v = q.front();
        //cout << "cur: " << v << ' ' << val[v] << '\n';
        q.pop();
        ans += val[v];
        for (auto [a, b] : adj2[v]) {
            b = (b + val[v]) % 3;
            b = (3 - b) % 3;
            if (val[a] == -1) {
                val[a] = b;
                q.push(a);
            }
            else if (val[a] != b) no;
        }
    }
  //  cout << "Fin\n";

    for (int i = 1; i <= m; i++) {
        if (val[i] != -1 || adj2[i].empty()) continue;

        vector<int> track;
        q.push(i);
        while (!q.empty()) {
            int a = q.front();
            q.pop();
            track.push_back(a);
            val[a] = 0;

            for (auto [u, v] : adj2[a]) {
                if (val[u] == -1) {
                    val[u] = 0;
                    q.push(u);
                }
            }
        }

        int tans = n * 100;
        for (int f = 0; f < 3; f++) {
            int tval = 0;
            // init
            for (auto k : track) val[k] = -1;
            val[i] = f;
            q.push(i);
            while (!q.empty()) {
                int a = q.front();
                q.pop();
                tval += val[a];

                for (auto [u, v] : adj2[a]) {
                    v = (v + val[a]) % 3;
                    v = (3 - v) % 3;
                    if (val[u] == -1) {
                        val[u] = v;
                        q.push(u);
                    }
                    else if (val[u] != v) tval = n * 100;
                }
            }
            tans = min(tans, tval);
        }

        if (tans == n * 100) no;
        ans += tans;
    }
    cout << ans << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}
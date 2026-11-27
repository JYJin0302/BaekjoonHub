#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

vector<pair<ll, ll>> adj[202020];

ll U[202020], D[202020], dist[202020];
ll ans = 0;

void dfs_D(int v, int pv = -1) {
    vector<ll> tmp;
    for (auto& f : adj[v]) if (f.first != pv) {
        dfs_D(f.first, v);
        tmp.push_back(dist[f.first] + f.second);
        D[v] = max(D[v], D[f.first]);
    }
    tmp.push_back(0);
    tmp.push_back(0);
    sort(tmp.rbegin(), tmp.rend());

    D[v] = max(D[v], tmp[0] + tmp[1]);
    dist[v] = tmp[0];
}

void dfs_U(int v, int pv = -1, ll v1 = 0, ll v2 = 0) {

    vector<pair<ll, ll>> tmp1, tmp2;
    if (pv != -1) {
        tmp1.push_back(mp(v1, pv));
        tmp2.push_back(mp(v2, pv));
    }
    for (auto& f : adj[v]) if (f.first != pv) {
        tmp1.push_back(mp(dist[f.first] + f.second, f.first));
        tmp2.push_back(mp(D[f.first], f.first));
    }

    while (tmp1.size() < 3) tmp1.push_back(mp(0, 0));
    while (tmp2.size() < 3) tmp2.push_back(mp(0, 0));

    sort(tmp1.rbegin(), tmp1.rend());
    sort(tmp2.rbegin(), tmp2.rend());

    for (auto& f : adj[v]) if (f.first != pv) {
        int curr = f.first;

        ll newVal1 = 0, newVal2 = 0;
        int cnt = 0;
        for (auto& i : tmp1) {
            if (i.second != curr) {
                cnt++;
                newVal1 += i.first;
            }
            if (cnt == 2) break;
        }
        for (auto& i : tmp2) {
            if (i.second != curr) {
                newVal2 += i.first;
                break;
            }
        }

        newVal2 = max(newVal2, newVal1);
        U[curr] = newVal2;
        newVal1 = f.second;
        for (auto& i : tmp1) {
            if (i.second != curr) {
                newVal1 += i.first;
                break;
            }
        }
        ans = max(ans, D[curr] + U[curr] + f.second);
        dfs_U(curr, v, newVal1, newVal2);
    }
}

void solve() {

    int n;
    cin >> n;

    vector<pair<ll, pair<int, int>>> edgeList;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        ll t;
        cin >> a >> b >> t;

        adj[a].push_back(mp(b, t));
        adj[b].push_back(mp(a, t));
        edgeList.push_back(mp(t, mp(a, b)));
    }

    dfs_D(1);
    dfs_U(1);
    cout << ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, s, e;
vector<int> adj[202020];
int mDist[202020];
int segL[404040], segR[404040];

void update(int ix, int val, int seg[]) {
    for (ix += n; ix; ix >>= 1) {
        seg[ix] = max(seg[ix], val);
    }
}

int getVal(int l, int r, int seg[]) {
    r++;
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
    }
    return res;
}


int goSolve(int l, int r, int t = 0) {
    if (r == l + 1) {
        int v1 = getVal(l, l, segL);
        int v2 = getVal(r, r, segR);
        return v1 - v2;
    }

    if (t == 0) {
        int v1 = getVal(l, l, segL);
        int v2 = getVal(l + 1, r, segR);

        int res = v1 - v2;
        int res2 = goSolve(l + 1, r, 1 - t);
        return max(res, res2);
    }
    else {
        int v1 = getVal(l, r - 1, segL);
        int v2 = getVal(r, r, segR);

        int res = v1 - v2;
        int res2 = goSolve(l, r - 1, 1 - t);
        return min(res, res2);
    }
}


void solve() {

    cin >> n >> s >> e;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> from(n + 1, -1);
    from[s] = s;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {

        int a = q.front(); q.pop();

        for (auto f : adj[a]) {
            if (from[f] == -1) {
                from[f] = a;
                q.push(f);
            }
        }
    }

    vector<int> route = { e };
    int cur = e;
    while (cur != s) {
        cur = from[cur];
        route.push_back(cur);
    }
    reverse(all(route));

    vector<int> dist(n + 1, -1);

    for (auto f : route) dist[f] = 0;
    int sz = route.size();

    for (int i = 0; i < sz; i++) {
        q.push(route[i]);
        int mx = 0;
        while (!q.empty()) {
            int a = q.front(); q.pop();
            mx = max(mx, dist[a]);
            for (auto f : adj[a]) {
                if (dist[f] == -1) {
                    dist[f] = dist[a] + 1;
                    q.push(f);
                }
            }
        }
        mDist[i] = mx + 1;
    } 

    for (int i = 0; i < sz; i++) {
        update(i, mDist[i] + i, segL);
        update(i, mDist[i] + sz - 1 - i, segR);
    }

    cout << goSolve(0, sz - 1);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
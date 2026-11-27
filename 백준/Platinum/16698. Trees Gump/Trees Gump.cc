#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second

int n;
vector<int> adj[1010];
pair<ll, ll> P[1010];
bool used[1010];
int sz[1010];

vector<pair<int, int>> ans;

pair<ll, ll> org, org2;

ll ccw(pair<ll, ll>& a, pair<ll, ll>& b, pair<ll, ll>& c) {
    ll res = a.x * b.y + b.x * c.y + c.x * a.y - (a.y * b.x + b.y * c.x + c.y * a.x);
    if (res != 0) res /= abs(res);
    return res;
}

bool cmp(pair<pair<ll, ll>, int>& p1, pair<pair<ll, ll>, int>& p2) {
    pair<ll, ll> a = p1.x;
    pair<ll, ll> b = p2.x;

    ll v1 = ccw(org2, org, a);
    ll v2 = ccw(org2, org, b);

    if (v1* v2 < 0) {
        return v1 > 0;
    }

    ll ccw1 = ccw(org, a, b);
    return ccw1 > 0;
}

void dfs2(int v, int pv = -1) {
    sz[v] = 1;
    for (auto f : adj[v]) if (f != pv) {
        dfs2(f, v);
        sz[v] += sz[f];
    }
}

void dfs(int v, int currIdx, vector<pair<pair<ll, ll>, int>>& curr, int pv = -1) {

    if (curr.size() + 1 != sz[v]) {
        assert(0);
    }
    if (curr.empty()) return;
    sort(curr.begin(), curr.end(), cmp);
    

    int ix = 0;
    for (auto f : adj[v]) if (f != pv) {

        if (ix >= curr.size()) assert(0);

        // connect
        ans.push_back(mp(currIdx, curr[ix].y));
        org2 = P[currIdx];
        org = P[curr[ix].y];
        int ndx = curr[ix].y;
        ix++;
        vector<pair<pair<ll, ll>, int>> tmp;
        while (ix < curr.size() && tmp.size() < sz[f] - 1) {
            tmp.push_back(curr[ix]);
            ix++;
        }
        dfs(f, ndx, tmp, v);
    }
    if (ix != curr.size()) assert(0);


}

void solve() {

    cin >> n;

    org = mp(1e9 + 1, 1e9 + 1);
    int sx = 0;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> P[i].first >> P[i].second;
        org = min(org, P[i]);
        if (org == P[i]) sx = i;
    }
    org2 = org;
    org2.y += 10;
    dfs2(sx);
    vector<pair<pair<ll, ll>, int>> curr;
    for (int i = 0; i < n; i++) {
        if (i != sx) curr.push_back(mp(P[i], i));
    }
    used[sx] = 1;
    dfs(0, sx, curr);

    //cout << "ANS: \n";
    for (auto f : ans)cout << f.first << ' ' << f.second << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    solve();
    return 0;
}

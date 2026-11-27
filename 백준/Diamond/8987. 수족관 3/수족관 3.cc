#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[300001], dp_2[300001];
vector<int> adj[300001];
vector<ll> res;

void dfs(int v, int pv = -1) {

    dp_2[v] = dp[v];
    vector<ll> tmp;
    for (auto i : adj[v]) if (i != pv) {

        dfs(i, v);
        tmp.push_back(dp_2[i]);
    }

    if (tmp.empty()) return;
    sort(tmp.rbegin(), tmp.rend());

    dp_2[v] += tmp[0];
    for (int i = 1; i < tmp.size(); i++) res.push_back(tmp[i]);
}


ll l[300001], r[300001], h[300001];
ll len[300001], slen[300001];

vector<ll> seg;
int o = 0;

void init(int l, int r, int n) {
    if (l == r) {
        seg[n] = l;
        return;
    }

    int m = (l + r) >> 1;
    init(l, m, n * 2);
    init(m + 1, r, n * 2 + 1);

    if (h[seg[n * 2]] <= h[seg[n * 2 + 1]]) seg[n] = seg[n * 2];
    else seg[n] = seg[n * 2 + 1];
}

int mins(int l, int r, int n, int sl, int sr) {
    if (l > sr || r < sl) return -1;
    if (l >= sl && r <= sr) return seg[n];

    int m = (l + r) >> 1;

    int i1 = mins(l, m, n * 2, sl, sr);
    int i2 = mins(m + 1, r, n * 2 + 1, sl, sr);

    if (i1 == -1) return i2;
    if (i2 == -1) return i1;

    if (h[i1] <= h[i2]) return i1;
    else return i2;
}

int co = 0;
int sz = 1;
void make_node(int l, int r, int pre_i = 0, int pre_h = 0) {

    if (l > r) return;

    ll tlen = slen[r] - slen[l-1];

    int mi = mins(1, sz, 1, l, r);

    if (mi == -1) {
        cout << "WTF\n";
        return;
    }
    ll nh = h[mi];

    co++;
    ll dp_val = (nh - pre_h) * tlen;
    dp[co] = dp_val;

    int tco = co;
    adj[pre_i].push_back(co);

    make_node(l, mi - 1, tco, nh);
    make_node(mi + 1, r, tco, nh);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    ll pa = -1, pb = -1;

    for (int i = 0; i < n / 2; i++) {

        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        if (i == 0) {
            pa = c, pb = d;
        }
        else {
            o++;
            l[o] = pa;
            r[o] = a;
            h[o] = b;
            len[o] = a - pa;
            slen[o] = slen[o - 1] + len[o];
            pa = c, pb = d;
        }
    }

    while (sz < o) sz *= 2;

    seg = vector<ll>(sz * 2);

    init(1, sz, 1);

    make_node(1, o);

    int k; cin >> k;
    k--;
    dfs(0);

    ll ans = dp_2[0];

    sort(res.rbegin(), res.rend());
    
    int tz = res.size();
    for (int i = 0; i < min(tz, k); i++) ans += res[i];
    cout << ans;
}
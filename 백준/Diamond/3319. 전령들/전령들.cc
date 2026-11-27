#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define mp make_pair
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}
int sgn(ll x) { return (x > 0) - (x < 0); }
struct P {
    ll x, y;
    P(ll x = 0, ll y = 0) : x(x), y(y) {}
    bool operator<(P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }
    bool operator==(P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(ll d) const { return P(x * d, y * d); }
    P operator/(ll d) const { return P(x / d, y / d); }
    ll dot(P p) const { return x * p.x + y * p.y; }
    ll cross(P p) const { 
        __int128 res = x;
        res *= p.y;
        __int128 res2 = y;
        res2 *= p.x;
        
        if (res < res2) return -1;
        if (res > res2) return 1;
        return 0;
    }
    ll cross(P a, P b) const { return (a - *this).cross(b - *this); }
    
};


vector<pair<ll, ll>> adj[101010];
ll V[101010];
ll S[101010];
ll ans[101010];
ll dist[101010];

P st[101010];
int st_sz = 0;
// 기울기 오름차순 - 기울기가 낮은게 더 빠른 것

void dfs(int v, int pv = -1) {

   /* cout << "Curr: " << v << " | ";
    for (int i = 0; i < st_sz; i++) cout << st[i] << ' ';
    cout << '\n';*/
    P cur(dist[v], dist[v] * V[v]);
    int l = 1, r = st_sz - 1, res = 0;
    while (l <= r) {
        int md = (l + r) >> 1;
        if ((st[md]-st[md-1]).cross(cur) <= 0) {
            r = md - 1;
        }
        else {
            l = md + 1;
            res = md;
        }
    }

    if (v != 1) {
        ans[v] = st[res].y + (dist[v] - st[res].x) * V[v] + S[v];
    }
   // cout << "Ans: " << res << " " << ans[v] << '\n';
    // insert {dist[v], ans[v]}
    cur = P(dist[v], ans[v]);

    l = 1, r = st_sz - 1, res = 0;
    while (l <= r) {
        int md = (l + r) >> 1;
        P b = st[md];
        P a = st[md - 1];

        if (a.cross(b, cur) > 0) {
            res = md;
            l = md + 1;
        }
        else {
            r = md - 1;
        }
    }

    int psz = st_sz;
    P prev = st[res + 1];
    if (v == 1) {
        st[res] = cur;
        st_sz = res + 1;
    }
    else {
        st[res + 1] = cur;
        st_sz = res + 2;
    }

    for (auto& [a, b] : adj[v]) if (a != pv) {
        dist[a] = dist[v] + b;
        dfs(a, v);
    }

    st_sz = psz;
    st[res + 1] = prev;

}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }
    for (int i = 2; i <= n; i++) cin >> S[i] >> V[i];
    
    dfs(1);
    for (int i = 2; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
}
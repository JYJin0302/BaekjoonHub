#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 1e17;
vector<pair<ll, ll>> plst;
int getIdx(pair<ll, ll> p) {
    int s = plst.size();

    int res = 0;
    if (p.x < p.y) {
        res += s;
        swap(p.x, p.y);
    }

    res += lower_bound(all(plst), p) - plst.begin();
    return res;
}

void solve() {

    ll a, b, p, q;
    cin >> a >> b >> p >> q;

    ll ta = a, tb = b;
    if (ta < tb) swap(ta, tb);


    plst.clear();
    plst.push_back(mp(ta, tb));
    while (ta && tb) {
        ta %= tb;
        if (ta < tb) swap(ta, tb);
        plst.push_back(mp(ta, tb));
    }

    
    int sn = plst.size();
    vector<vector<ll>> dist(2, vector<ll>(sn, INF));
    if (mp(a, b) == plst[0]) dist[0][0] = 0;
    else dist[1][0] = 0;

    // 0 : a >= b, 1 : a < b
    for (int i = 0; i < sn - 1; i++) {
        dist[0][i] = min(dist[0][i], dist[1][i] + p);

        ll ta = plst[i].x, tb = plst[i].y;

        dist[0][i + 1] = min(dist[0][i+1], dist[0][i] + p);
        ll na = ta % tb;
        ll cnt = (ta - na) / tb;

        if (INF / cnt > q && cnt * q + dist[0][i] < INF) {
            dist[1][i + 1] = min(dist[1][i + 1], dist[0][i] + cnt * q);
        }
        if (INF / cnt > q && cnt * q + dist[1][i] < INF) {
            dist[0][i + 1] = min(dist[0][i + 1], dist[1][i] + cnt * q);
        }
    }

    cout << min(dist[0][sn - 1], dist[1][sn - 1]) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
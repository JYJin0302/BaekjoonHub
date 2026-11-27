#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()


struct Q {
    int t, idx;
    ll x, y;
};
int maxN = 300000;
int segX[606060], segD[606060];
void update(int ix, int val, int seg[]) {
    for (ix += maxN; ix; ix >>= 1) {
        seg[ix] += val;
    }
}

int getSum(int l, int r, int seg[]) {
    int res = 0;
    for (l += maxN, r += maxN; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += seg[l++];
        if (r & 1) res += seg[--r];
    }
    return res;
}

vector<ll> xpos, dist;
int getIdx(ll val, vector<ll>& v) {
    return lower_bound(all(v), val) - v.begin();
}


map<pair<int, int>, bool> used;

void solve() {

    vector<Q> qL;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            ll x;
            cin >> x;
            xpos.push_back(x);
            xpos.push_back(-x);
            dist.push_back(x * x);
            qL.push_back({ t, i, x, -1 });
        }
        else {
            ll x, y;
            cin >> x >> y;
            xpos.push_back(x);
            dist.push_back(x * x + y * y);
            qL.push_back({ t, i, x, y });
        }
    }

    sort(all(xpos));
    xpos.erase(unique(all(xpos)), xpos.end());
    sort(all(dist));
    dist.erase(unique(all(dist)), dist.end());

    for (auto f : qL) {
        if (f.t == 1) {
            auto x = f.x;
            int l = getIdx(-x, xpos);
            int r = getIdx(x, xpos);
            int ans = getSum(l + 1, r, segX);
            int ix = getIdx(x * x, dist);
            ans -= getSum(0, ix + 1, segD);
            cout << ans << '\n';
        }
        else {
            auto [x, y] = mp(f.x, f.y);
            bool ud = used[mp(x, y)];
            int ix = getIdx(f.x, xpos);
            update(ix, 1 - 2*ud, segX);
            ix = getIdx(x * x + y * y, dist);
            update(ix, 1 - 2*ud, segD);
            used[mp(x, y)] ^= 1;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll t, n, l, k;
ll seg[2002020];
void update(int ix, ll val) {
    for (ix += n; ix; ix >>= 1) {
        seg[ix] = max(seg[ix], val);
    }
}

ll getMax(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1)res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
    }
    return res;
}

void solve() {

    cin >> t >> n >> l >> k;

    vector<ll> T(n); for (auto& i : T) cin >> i;
    vector<ll> tSeg(n);
    for (int i = 0; i < n; i++) {
        if (i == n - 1) tSeg[i] = t - T[i] + T[0];
        else tSeg[i] = T[i + 1] - T[i];
        update(i, tSeg[i]);
    }

    vector<ll> K(k);
    for (auto& i : K) cin >> i;
    vector<ll> D;
    for (int i = 1; i < k; i++) D.push_back(K[i] - K[i - 1]);

    ll cPos = 0, cTurn = 0, ans = 0;
    int ix = 0;
    while (cPos < l) {
        ll d = D[ix];

        int nx = lower_bound(all(T), cTurn) - T.begin();
        
        if (nx == n) nx = 0;
        ll cAble = (T[nx] - cTurn + t) % t;

        if (cAble >= d) {
            (cTurn += d) %= t;
            ans += d;
            cPos += d;
        }
        else {
            cTurn = T[nx];
            ans += cAble;

            if (seg[1] < d) {
                cout << "What is that map newbie..." << '\n';
                return;
            }

            ll t1 = getMax(nx, n);
            int l = -1, r = -1;
            if (t1 >= d) {
                l = nx, r = n - 1;
            }
            else {
                l = 0, r = nx - 1;
            }
            int tl = l;
            int ret = -1;
            while (l <= r) {
                int md = (l + r) >> 1;
                ll res = getMax(tl, md + 1);
                if (res >= d) {
                    ret = md;
                    r = md - 1;
                }
                else l = md + 1;
            }

            assert(ret != -1);

            ans += (T[ret] - T[nx] + t) % t;
            cTurn = T[ret];

            (cTurn += d) %= t;
            ans += d;
            cPos += d;
        }


        ix++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
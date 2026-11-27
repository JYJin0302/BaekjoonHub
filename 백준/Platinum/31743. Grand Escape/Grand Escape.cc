#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> xpos;
int getIdx(int x) {
    return lower_bound(all(xpos), x) - xpos.begin();
}
int sn = 600005;

ll seg[1208080];
void update(int ix, int val) {
    for (ix += sn; ix; ix >>= 1) {
        seg[ix] += val;
    }
}

ll getSum(int l, int r) {
    ll res = 0;
    for (l += sn, r += sn; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += seg[l++];
        if (r & 1) res += seg[--r];
    }
    return res;
}

void solve() {


    vector<pair<int, pair<int, int>>> A;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r, h;
        cin >> l >> r >> h;

        A.push_back(mp(h, mp(l, r)));
        xpos.push_back(l);
        xpos.push_back(r);
    }


    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int w, h;
        cin >> w >> h;

        A.push_back(mp(h, mp(w, -i-1)));
        xpos.push_back(w);
    }
    xpos.push_back(1e9 + 10);
    sort(all(xpos));
    xpos.erase(unique(all(xpos)), xpos.end());
    

    sort(all(A));
    vector<ll> ans(m+1);
    for (auto& i : A) {

        auto [a, b] = i.second;
        int h = i.first;

        if (b < 0) {
            int ix = getIdx(a);
            ll res = getSum(0, ix + 1);
            ans[-b] = res + h;
        }
        else {
            a = getIdx(a);
            b = getIdx(b);
            update(a, h);
            update(b + 1, -h);
        }
    }

    for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
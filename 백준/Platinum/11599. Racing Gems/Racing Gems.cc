#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

int n, r, w, h;
vector<ll> num;

int seg[202020];
void update(int ix, int val) {
    for (ix += n; ix; ix >>= 1) {
        seg[ix] = max(seg[ix], val);
    }
}

int getVal(int l, int r) {
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
    }
    return res;
}

void solve() {

    cin >> n >> r >> w >> h;

    vector<pair<ll, ll>> A(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        A[i] = mp(b - a * r, b + a * r);
        num.push_back(b + a * r);
    }

    sort(all(num));
    num.erase(unique(all(num)), num.end());

    sort(all(A));

    int ans = 0;
    for (auto [a, b] : A) {
        int ix = lower_bound(all(num), b) - num.begin();
        int v = getVal(0, ix + 1) + 1;
        ans = max(ans, v);
        update(ix, v);
    }
    cout << ans;

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
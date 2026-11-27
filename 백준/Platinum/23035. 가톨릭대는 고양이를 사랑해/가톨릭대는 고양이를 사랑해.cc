#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> num;
int N, seg[202020];

void update(int ix, int val) {
    for (ix += N; ix; ix >>= 1) {
        seg[ix] = max(seg[ix], val);
    }
}

int getV(int l, int r) {
    int res = 0;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    vector<pair<int, int>> A;

    cin >> N;
    for(int i =0 ; i< N; i++){

        ll a, b;
        cin >> a >> b;

        if (a <= n && b <= m) {
            A.push_back(mp(a, b));
            num.push_back(b);
        }
    }

    sort(all(num));
    num.erase(unique(all(num)), num.end());

    sort(A.begin(), A.end());

    int ans = 0;
    for (auto [a, b] : A) {
        int ix = lower_bound(all(num), b) - num.begin();
        int val = getV(0, ix + 1);
        ans = max(ans, val + 1);
        update(ix, val+1);
    }
    cout << ans << '\n';
}
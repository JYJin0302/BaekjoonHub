#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


vector<ll> num;
ll getIdx(ll x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}

const int MAX_N = 200001;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll seg[MAX_N * 4 + 10];

void update(int ix, ll val) {
    for (ix += 2*MAX_N + 3; ix; ix >>= 1) {
        seg[ix] = min(seg[ix], val);
    }
}

ll getMin(int l, int r) {
    ll res = INF;
    for (l += 2*MAX_N + 3, r += 2*MAX_N + 3; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, seg[l++]);
        if (r & 1) res = min(res, seg[--r]);
    }
    return res;
}

void solve() {

    memset(seg, INF, sizeof(seg));

    ll e, h, n;
    cin >> e >> h >> n;

    vector<ll> A(n + 10);
    for (int i = 1; i <= n; i++) cin >> A[i];

    vector<ll> E(n + 1), M(n + 1);
    for (int i = 1; i <= n; i++) {
        E[i] = max(0ll, A[i] - A[i - 1]);
        M[i] = abs(A[i] - A[i - 1]);
    }

    for (int i = 1; i <= n; i++) {
        E[i] += E[i - 1];
        M[i] += M[i - 1];
    }

    for (int i = 0; i <= n; i++) {
        num.push_back(E[i]);
        num.push_back(E[i] - A[i]);
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    int sn = num.size();
    update(getIdx(0), 0);

   // cout << "upd: 0 0\n";

    for (int i = 1; i <= n; i++) {

        ll lE = E[i] - e + h - A[i];
        lE = getIdx(lE);
        ll val1 = getMin(lE, sn) + M[i] + h - A[i];
      //  cout << "Search: " << E[i] - e + h - A[i] << ' ' << getMin(lE, sn) << ' ' << M[i] + h - A[i] << '\n';

        lE = E[i] - e;
        lE = getIdx(lE);
        ll val2 = getMin(lE, sn) + M[i] + A[i];
       // cout << "Search: " << E[i] - e << ' ' << getMin(lE, sn) << ' ' << M[i] + A[i] << '\n';

        if (i == n) {
            //cout << val1 << ' ' << val2 << '\n';
            cout << val2 << '\n';
            return;
        }
        
        int ix1 = getIdx(E[i+1]);
        if (val1 < INF) update(ix1, val1 - M[i+1] + h-A[i+1]);
       // cout << "upd:  " << E[i+1] << ' ' << val1 - M[i+1] + h - A[i+1] << '\n';

        ix1 = getIdx(E[i+1] - A[i+1]); // E[i+1] A[i+1] ??
        if (val2 < INF) update(ix1, val2 - M[i+1] + A[i+1]);
       // cout << "upd:  " << E[i+1] - A[i+1] << ' ' << val2 - M[i+1] + A[i+1] << '\n';

       //  cout << val1 << ' ' << val2 << '\n';

    }



}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}
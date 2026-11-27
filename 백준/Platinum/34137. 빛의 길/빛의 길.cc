#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

ll seg[606060];
ll lazy[606060];

void goLazy(int l, int r, int n){
    if (lazy[n]){
        seg[n] = lazy[n] * (r-l+1);
        if (l != r){
            lazy[n*2] = lazy[n];
            lazy[n*2+1] = lazy[n];
        }
        lazy[n] = 0;
    }
}
void update(int l, int r, int n, int sl, int sr, ll u){
    goLazy(l, r, n);
    if (l > sr || r < sl) return;
    if (l >= sl && r <= sr) {
        lazy[n] = u;
        goLazy(l, r, n);
        return;
    }

    int md  =(l+r)>>1;
    update(l ,md, n*2, sl, sr, u);
    update(md+1, r, n*2+1, sl, sr, u);
    seg[n] = seg[n*2] + seg[n*2+1];
}

ll getS(int l, int r, int n, int sl, int sr){
    goLazy(l, r, n);
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];
    
    int md = (l+r)>>1;
    return getS(l, md, n*2, sl, sr) + getS(md+1,r ,n*2+1, sl, sr);
}

void solve() {

    ll n, m, t, k;
    cin >>  n>> m >> t >> k;

    vector<int> col(m+1);
    for(int i = 1; i <= m; i++){
        cin >> col[i];
    }


    vector<array<ll, 4>> qur;

    while(k--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        array<ll, 4> tmp = {n+1-a, b, c, d};
        qur.push_back(tmp);
    }
    sort(all(qur));

    for(int i = 1; i <= m; i++) {
        array<ll, 4> tmp = {n, i, i, col[i]};
        qur.push_back(tmp);
    }

    vector<ll> ans(t+1);
    for(auto f: qur){
        ll h = f[0];
        ll l = f[1], r = f[2];
        int cc = f[3];

        ll res = h * (r - l + 1) - getS(1, m, 1, l, r);
        ans[cc] += res;
        update(1, m, 1, l, r, h);
    }

    for(int i = 1; i <= t; i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
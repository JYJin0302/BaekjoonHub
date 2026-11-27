#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 998244353;

ll seg[2206060];
ll lazy[2206060];

void goLazy(int l, int r, int n){
    if (lazy[n] ==0) lazy[n] = 1;
    if (lazy[n] != 1){
        seg[n] = seg[n]*lazy[n] % mod;
        if(l != r){
            lazy[n*2] = lazy[n*2]* lazy[n] % mod;
            lazy[n*2+1] = lazy[n*2+1]* lazy[n] % mod;
        }
        lazy[n] = 1;
    }
}

void update_add(int l, int r, int n, int ix, ll val){
    goLazy(l, r, n);
    if (l > ix || r < ix) return;
    if (l == ix && r == ix){
        seg[n] = val;
        return;
    }
    int md = (l+r)>>1;
    update_add(l, md, n*2, ix, val);
    update_add(md+1, r, n*2+1, ix, val);
    seg[n] = (seg[n*2] + seg[n*2+1]) % mod;
}

void update_mul(int l, int r, int n, int sl, int sr){
    goLazy(l, r, n);
    if(l > sr || r < sl) return;
    if (l >= sl && r <= sr){
        lazy[n] = 2;
        goLazy(l, r, n);
        return;
    }
    int md = (l+r)>>1;
    update_mul(l, md, n*2, sl, sr);
    update_mul(md+1,r, n*2+1, sl, sr);
    seg[n] = (seg[n*2] + seg[n*2+1]) %  mod;

}

ll getS(int l, int r, int n, int sl, int sr){
    goLazy(l, r, n);
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int md = (l+r)>>1;
    return (getS(l, md, n*2, sl, sr) + getS(md+1,r, n*2+1, sl, sr)) % mod;

}

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for(auto& i : A) cin >> i.first >> i.second;
    sort(all(A));

    for(auto[a,b] : A){

        ll res = (1 + getS(1, n*2, 1, a, b)) % mod;

        update_mul(1, n*2, 1, b+1, n*2);
        update_add(1, n*2, 1, b, res);
    }

    ll ans = getS(1, n*2, 1, 1, n*2);
    cout << ans << '\n';
    

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


struct D{
    ll val[3][3];

    D(array<ll, 3> _v = {0, 0, 0}){
        memset(val, 0, sizeof val);  
        for(int i = 0; i < 3; i++){
            val[i][2-i] = _v[i];
        }
        val[0][0] = _v[0] + _v[2];
    }
    D operator+(const D& o) const {
        D res;
        for(int r = 0 ; r < 3; r++){
            for(int l = 0; l + r < 3; l++){
                if (l + r < 1) continue;
                for(int a= 0; a < 3; a++){
                    for(int b = 0; b < 3; b++){
                        res.val[a][b] = max(res.val[a][b], val[a][r] + o.val[l][b]);
                    }
                }
            }
        }
        return res;        
    }
} seg[202020];

array<ll, 3> A[40404];

void init(int l, int r, int n){
    if (l == r) {
        seg[n] = A[l];
        return;
    }
    int md = (l+r)>>1;
    init(l ,md, n*2);
    init(md+1, r, n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

void update(int l, int r, int n, int u, ll val){
    if(l > u || r < u) return;
    if (l == u && r == u){
        seg[n] = A[l];
        return;
    }
    int md= (l+r)>>1;
    update(l, md, n*2, u, val);
    update(md+1, r, n*2+1, u, val);
    seg[n] = seg[n*2]+ seg[n*2+1];
}

void solve(){
    
    int n, m;
    cin >> n >> m;

    vector<ll> T(n + 3);
    for(int i = 0; i < n ;i++){
        cin >> T[i];
    }
    
    
    for(int i = 0 ; i < n; i+= 3){
        A[i/3] = {T[i], T[i+1], T[i+2]};
    }
    
    n = (n + 2) / 3;
    init(0, n - 1, 1);
    
    ll ans = 0;
    while( m--){
        ll x, v;
        cin >> x >> v;
        x--;

        int i1 = x/3;
        int i2 = x % 3;
        A[i1][i2] = v;

        
        update(0, n - 1, 1, i1, v);

        
        ll mx = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                mx = max(mx, seg[1].val[i][j]);
            }
        }
        ans += mx;
    }
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

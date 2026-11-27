#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define all(x) x.begin(), x.end()

ll gcd(ll a, ll b){
    if ( a== 0) return b;
    return gcd(b% a, a);
}

int n;
ll seg[303030];
ll segG[303030];

void add(int ix, ll val){
    while(ix <= n){
        seg[ix] += val;
        ix += ix & -ix;
    }
}

ll getS(int ix){
    ll res = 0;
    while(ix){
        res += seg[ix];
        ix -= ix & -ix;
    }
    return res;
}

void update(int l, int r, int n, int u, ll val){
    if (l > u || r < u) return;
    if ( l == u && r == u){
        segG[n] += val;
        return;
    }

    int md = (l+r)>>1;
    update(l, md, n*2, u, val);
    update(md+1, r, n*2+1, u, val);
    segG[n] = gcd(abs(segG[n*2]), abs(segG[n*2+1]));
}

ll getR(int l, int r, int n, int sl, int sr){
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return abs(segG[n]);
    int md = (l+r)>>1;
    ll v1 = getR(l ,md, n*2, sl, sr);
    ll v2 = getR(md+1, r, n*2+1, sl, sr);
    return gcd(v1, v2);
}

void solve() { 
    
    cin >> n;

    vector<ll> A(n+1);
    for(int i = 1;i <=n ;i++) cin >> A[i];

    for(int i = 1; i<= n; i++){
        add(i, A[i] - A[i-1]);
    }

    for(int i = 1; i <= n; i++){
        update(1, n, 1, i, A[i] - A[i-1]);
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        
        ll t, a, b;
        cin >> t >> a >> b;
        if (t){
            add(a, t);
            add(b+1, -t);

            update(1, n, 1, a, t);
            update(1, n, 1, b+1, -t);
        }
        else{

            ll v1 = getS(a);
            ll r1 = getR(1, n, 1, a+1, b);

            cout << gcd(v1, r1) << '\n';
        }
        
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

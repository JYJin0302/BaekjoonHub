#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;

void update(int l, int r, int n, int u){
    if (l > u || r < u) return;
    if (l == u && r == u){
        seg[n] = 1;
        return;
    }
    
    int mid = (l+r)/2;
    update(l, mid, n*2, u);
    update(mid+1, r, n*2+1, u);
    
    seg[n] = seg[n*2] + seg[n*2+1];
}

ll ssum(int l, int r, int n, int sl, int sr){
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];
    
    int mid = (l+r)/2;
    return ssum(l, mid, n*2, sl, sr) + ssum(mid+1, r, n*2+1, sl, sr);
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, mod = 1e9+9;
    cin >> n;
    
    vector<ll> ind(n+1), R(n);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        ind[x] = i;
    }
    for(auto& i : R) cin >> i;
    
    int size = 1;
    while(size < n) size*=2;
    
    seg = vector<ll>(size*2);
    
    
    ll temp = 0;
    for (int i = 0;i < n; i++){
        int tt = ind[R[i]];
        temp += tt - ssum(size, size*2-1, 1, size, size + tt);
        update(size, size*2-1, 1, size +tt);
    }
    ll ans = temp;
    for (int i = n - 1; i > 0; i--){
        int tt = ind[R[i]];
        temp += tt - (n - 1 - tt);
        ans += temp;
        ans %= mod;
    }
    
    cout << ans * n % mod;
    
}
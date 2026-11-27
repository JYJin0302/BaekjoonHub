#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg, A;

void init(int l, int r, int n){
    if (l == r) return;
    int mid = (l+r)/2;
    init(l, mid, n*2);
    init(mid+1, r, n*2+1);
    seg[n] = seg[n*2] + seg[n*2+1];
}

void update(int l, int r, int n, int u){
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n]++;
        return;
    }
    
    int mid = (l+r)/2;
    update(l, mid, n*2, u);
    update(mid+1, r, n*2+1, u);
    seg[n] = seg[n*2]+ seg[n*2+1];
}

ll ssum(int l, int r, int n, int sl, int sr){
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];
    
    int mid =(l+r)/2;
    return ssum(l, mid, n*2, sl, sr) + ssum(mid+1, r, n*2+1, sl, sr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        
        int sn = 1;
        while(sn < n) sn*=2;
        
        A = vector<ll>(n);
        seg = vector<ll>(sn*2);
        
        for(auto& i : A) cin >> i;
        
        init(0, n-1, 1);
        
        ll ans = 0;
        for (int i : A){
            ans += ssum(0, n-1, 1, i-1, n-1) - ssum(0, n-1, 1, i-1, i-1);
            update(0, n-1, 1, i-1);
        }
        cout << ans << '\n';
    }
    
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> seg;

void init(int l, int r, int n){
    if (l == r) return;
    int mid = (l+r)/2;
    init(l, mid, n*2);
    init(mid+1, r, n*2+1);
    seg[n] = max(seg[n*2], seg[n*2+1]);
}

ll solve(int l, int r, int n, int sl, int sr){
    
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];
    
    int mid = (l+r)/2;
    return max(solve(l, mid, n*2, sl, sr), solve(mid+1, r, n*2+1, sl, sr));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<ll> h(n), t(n-1);
    for(auto& i : h) cin >> i;
    for(auto& i : t) cin >> i;
    
    int sn = 1;
    while(sn < n) sn *= 2;
    seg = vector<ll> (sn*2);
    
    for (int i = 0; i < n; i++){
        seg[sn + i] = h[i];
    }
    init(0, sn-1, 1);
    
    vector<ll> R(n), L(n);
    ll r = 0, l = n-1, v = 0;
    
    for(int i = 0; i < n; i++){
        while(r < n && h[r] >= v) {
            v += t[r];
            r++;
        }
        if (i != n-1) v -= t[i];
        R[i] = r-1;
    }
    
    v = 0;
    for(int i = n-1; i >= 0; i--){
        while(l >= 0 && h[l] >= v){
            v += t[l-1];
            l--;
        }
        if (i != 0) v -= t[i-1];
        L[i] = l+1;
    }
    
    for(int i = 0; i < n; i++){
        cout << solve(0, sn-1, 1, L[i], R[i]) << ' ';
    }
    
}
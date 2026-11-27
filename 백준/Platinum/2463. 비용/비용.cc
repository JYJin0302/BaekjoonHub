#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9;

ll root[100001];
ll sz[100001];

ll find(int n){
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

struct T{
    ll val;
    ll x, y;
    
    bool operator<(T& o){
        return val > o.val;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) root[i] = i, sz[i] = 1;
    
    vector<T> A(m);
    for (int i = 0; i < m; i++){
        cin >> A[i].x >> A[i].y >> A[i].val;
    }
    
    sort(A.begin(), A.end());
    
    ll ts = 0;
    ll ans = 0;
    
    for (auto i : A){
        ll a = i.x, b = i.y;
        a = find(a), b = find(b);
        
        if (a != b){
            ts += sz[a]*sz[b];
            ts %= mod;
            sz[a] += sz[b];
            root[b] = a;
        }
        
        ans += ts * i.val;
        ans %= mod;
    }
    cout << ans;
}
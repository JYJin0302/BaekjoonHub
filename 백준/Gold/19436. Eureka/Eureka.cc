#include <bits/stdc++.h>
using namespace std;
using ll = long long;

typedef pair<ll, ll> P;

#define x first
#define y second

const ll mod = 1e9+7;

ll gcd(ll a, ll b){
    if (a > b) swap(a, b);
    
    if (a == 0) return b;
    return gcd(b%a, a);
}

ll pow2[1001];

P getP(P& a, P& b){
    
    P res;
    res.x = b.x-a.x, res.y = b.y-a.y;
    
    ll g = gcd(abs(res.x), abs(res.y));
    g = max(1ll, g);
    res.x /= g, res.y /= g;
    
    if (res.x == 0 && res.y != 0) res.y = 1;
    if (res.x != 0 && res.y == 0) res.x = 1;
    
    if (res.x < 0) {
        res.x *= -1, res.y *= -1;
    }
    
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    pow2[0] = 1;
    for(int i = 1; i <= 1000; i++){
        pow2[i] = pow2[i-1]*2 % mod;
    }
    
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        
        vector<P> A(n);
        for(auto& i : A) cin >> i.x >> i.y;
        
        sort(A.begin(), A.end());
        
        map<P, int> cnt;
        
        ll ans = 0;
        for(int i = 0; i < n; i++){
            cnt.clear();
            for (int j = i+1; j < n; j++){
                
                P tmp = getP(A[i], A[j]);
                cnt[tmp]++;
            }
            
            ll val = cnt[{0, 0}];
            P tx = {0, 0};
            auto iter = cnt.begin();
            while(iter != cnt.end()){
                if (iter->x != tx) ans = (ans + pow2[(iter->y)+val] - pow2[val] + 2*mod) % mod;
                else ans = (ans + pow2[iter->y] - 1 + mod) % mod;
                iter++;
            }
        }
        
        cout << ans << '\n';
    }
}
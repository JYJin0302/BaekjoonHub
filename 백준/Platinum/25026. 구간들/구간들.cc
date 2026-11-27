#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;

ll n, sn;
vector<ll> seg;
map<ll, int> ix;

void update(int l, int r, int n, int u){
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n]++;
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
    return ssum(l, mid, n*2, sl,sr) + ssum(mid+1, r, n*2+1, sl, sr);
}

ll f(ll b, ll ex){
    ll res = 1;
    ll tmp = b;
    while(ex){
        if (ex % 2 == 1) res *= tmp;
        tmp = (tmp*tmp) % mod;
        res %= mod;
        ex >>= 1;
    }
    return res;
}

bool cmp(pair<ll, ll>& a, pair<ll, ll>& b){
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    map<ll, bool> cnt;
    vector<int> num;
    vector<pair<ll,ll>> inp;
    for (int i =0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        
        if (b - a > 0){
            if (!cnt[b]) {
                cnt[b] = 1;
                num.push_back(b);
            }
            if (!cnt[a]){
                cnt[a] = 1;
                num.push_back(a);
            }
            
            inp.push_back({a, b});
        }
    }
    
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size(); i++){
        ix[num[i]] = i;
    }
    
    n = num.size();
    int m = inp.size();
    sn = 1;
    while(sn < n) sn *= 2;
    seg = vector<ll>(sn*2);
    
    
    ll ans1 = 0, ans2 = 0;
    // x val
    sort(inp.begin(), inp.end());
    
    for (int i = 0; i < m; i++){
        ll a, b;
        tie(a, b) = inp[i];
        
        int ix1 = ix[a], ix2 = ix[b];
        
        ll v2 = ssum(0, sn-1, 1, ix1, n-1);
        ll v1 = v2 - seg[sn + ix1];
        
        update(0, sn-1, 1, ix2);
        ans1 = (ans1 + f(2, v1)*(mod - a)) % mod;
        ans2 = (ans2 + f(2, v1)) % mod;
    }
    
    // 초기화
    seg= vector<ll>(sn*2);
    // y val
    sort(inp.begin(), inp.end(), cmp);
    
    for (int i = 0; i < m; i++){
        ll a, b;
        tie(a, b) = inp[i];
        
        int ix1 = ix[a], ix2 = ix[b];
        
        ll v2 = ssum(0, sn-1, 1, 0, ix2);
        ll v1 = v2 - seg[sn + ix2];
        
        update(0, sn-1, 1, ix1);
        ans1 = (ans1 + f(2, v1)*b) % mod;
        //ans2 = (ans2 + f(2, v2)) % mod;
    }
    
    cout << ans1 << ' ' << ans2;
}
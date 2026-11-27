#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, k;

int seg[2002020];
void update(int ix, int val){
    for(ix += n + 5; ix; ix >>= 1){
        seg[ix] = max(seg[ix], val);
    }
}

const int INF = 1e9;
int getM(int l, int r){
    int res = -INF;
    for(l += n + 5, r+= n + 5; l < r; l>>=1, r>>=1){
        if (l &1) res = max(res, seg[l++]);
        if (r & 1) res = max(res, seg[--r]);
    }
    return res;
}

void solve(){
    
    cin >> n >> k;

    vector<ll> A(n);
    for(auto& i : A){
        cin >> i;
    }

    vector<ll> sA(n);
    for(int i = 0; i < n;i++){
        sA[i] = A[i] + (i ? sA[i-1] : 0);
    }

    vector<ll> num = sA;
    num.push_back(0);
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    for(int i = 0; i <= n*2 + 10 ;i++) seg[i] = -INF;
    int ix = lower_bound(all(num), 0) - num.begin() + 1;
    update(ix, 0);

    int sn = (int)num.size();
    vector<int> dp(n+1);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ll val = sA[i-1];
        int ix = lower_bound(all(num), val - k + 1) - num.begin();

        int res = getM(1, ix + 1);
        dp[i] = max(0, res + 1);
        ans = max(ans, res + 1);
        int iter = lower_bound(all(num), val) - num.begin() + 1;
        update(iter, dp[i]);
    }
    cout << ans << '\n';
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
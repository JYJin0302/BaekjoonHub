#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, k, d;
int seg[2101010];

void update(int ix, int val){
    for(ix += 500050; ix; ix>>=1){
        seg[ix] = max(seg[ix], val);
    }
}

int getS(int l, int r){
    int res = 0;
    for(l += 500050, r += 500050; l < r; l >>= 1, r >>= 1){
        if (l & 1) res= max(res, seg[l++]);
        if (r&1) res = max(res, seg[--r]);
    }
    return res;
}

void solve(){

    cin >> n >> k >> d;

    vector<int> A(n);
    for(auto& i : A) cin >> i;
    vector<int> dp(n);
    vector<int> dp2(k);


    int ans = 0;
    for(int i =0 ; i < n ;i++){
        int val = A[i];
        int l = max(1, val - d);
        int r = min(500010, val + d);

        int mx = getS(l, r+1);
        mx = max(mx, dp2[val%k]);

        dp[i] = mx + 1;
        dp2[val%k] = max(dp2[val%k], dp[i]);
        update(val, mx + 1);
        ans = max(ans, dp[i]);
        //cout << dp[i] << ' ';
    }

    cout << ans << '\n';



}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

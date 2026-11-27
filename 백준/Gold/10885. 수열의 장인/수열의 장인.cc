#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        
        ll ans = -2;
        int cnt = 0;
        vector<ll> A(n);
        for(auto& i : A) {
            cin >> i;
            ans = max(ans, i);
        }
        
        vector<pair<int, int>> dp(n);
        dp[0] = {(A[0] > 0 ? A[0] : 0), (A[0] < 0 ? -A[0] : 0)};
        
        for(int i = 1; i < n; i++){
            if (A[i] == 0) {
                dp[i] = {0, 0};
            }
            else if (A[i] == 1){
                dp[i] = {max(1, dp[i-1].x), dp[i-1].y};
            }
            else if (A[i] == -1){
                dp[i] = {dp[i-1].y, max(1, dp[i-1].x)};
            }
            else if (A[i] == 2){
                dp[i] = {max(2, dp[i-1].x + 1), (dp[i-1].y > 0 ? dp[i-1].y + 1 : 0)};
            }
            else{
                dp[i] = {(dp[i-1].y > 0 ? dp[i-1].y + 1 : 0), max(2, dp[i-1].x + 1)};
            }
        }
        
        int mval = 0;
        for  (int i = 0; i < n; i++){
             mval = max(mval, dp[i].x);
        }
        
        ll ans2 = 1;
        if (mval <= 1) ans2 = mval;
        else{
        for (int i = 1; i < mval; i++){
            ans2 *= 2;
            ans2 %= mod;
        }
        }
        
        
        cout << max(ans, ans2) << '\n';
    }
    
}
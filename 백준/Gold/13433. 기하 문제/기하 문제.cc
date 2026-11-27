#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    cout << fixed << setprecision(20);
    vector<ll> A(n);
    for(auto& i : A) cin >> i;
    
    sort(A.begin(), A.end());
    
    double ans = 1e12;
    do{
        
        vector<double> dp(n);
        dp[0] = 0;
        for(int i = 1; i < n; i++){
            double t = 0;
            ll v = 0;
            for (int j = i-1; j >= 0; j--){
                double d = sqrt((A[j] + A[i])*(A[j] + A[i]) - (A[j] - A[i]) * (A[j] - A[i]));
                
                if (A[j] > v) t = max(t, dp[j] + d);
                v = max(v, A[j]);
            }
            dp[i] = t;
        }
        
        double tans = 0;
        for (int i = 0; i < n; i++) tans = max(tans, dp[i] - dp[0]);
        
        ans = min(ans, tans);
        
    } while( next_permutation(A.begin(),A.end()));
    
    cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    int n;
    cin >> n;
    vector<ld> A(n);
    for(auto& i : A) cin >> i;

    sort(all(A));

    ld ans = 0;
    for(auto f : A) ans += f*2;

    do{

        vector<ld> dp(n);
        dp[0] = A[0];
        for(int i = 1; i < n; i++){
            ld mx = A[i];
            for(int j = 0; j < i; j++){
                ld cur = dp[j] + sqrtl((A[i] + A[j]) * (A[i] + A[j]) - (A[i] - A[j]) * (A[i] - A[j]));
                mx = max(mx, cur);
            }
            dp[i] = mx;
        }
        ld res = 0;
        for(int i = 0; i < n ;i++) res = max(res, dp[i] + A[i]);
        ans = min(ans, res);


    }while(next_permutation(all(A)));
    cout << fixed << setprecision(3);
    cout << ans << '\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
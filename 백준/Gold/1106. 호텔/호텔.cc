#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() { 
    
    int c, n;
    cin >> c  >> n;

    vector<pair<int, int>> A(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        A[i] = mp(a, b);
    }

    vector<int> dp(c+200, 1e8);
    dp[0] = 0;

    int ans = 1e8;
    for(int i = 1; i< c+200; i++){
        for(auto[a,b] : A){
            if (b <= i){
                dp[i] = min(dp[i], dp[i-b] + a);
            }
        }

        if (i >= c) ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

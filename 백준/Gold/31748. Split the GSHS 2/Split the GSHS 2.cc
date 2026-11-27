#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

vector<int> nxt[101010];
ll dp[101010];

void solve(){
    
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for(int i = 1; i <= n; i++) cin >> A[i];

    for(int i = 1; i <= n; i++){
        if (i - A[i] >= 1){
            nxt[i-A[i]].push_back(i);
        }
    }

    dp[0] = 1;
    for(int i = 1;i <= n; i++){
        ll b = dp[i-1];
        for(auto f: nxt[i]){
            dp[f] = (dp[f] + b) % mod;
        }

        int ni = i + A[i];
        if (ni <= n && ni - A[ni] != i) {
            dp[ni] = (dp[ni] + b) % mod;
        }
    }

    cout << dp[n] << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
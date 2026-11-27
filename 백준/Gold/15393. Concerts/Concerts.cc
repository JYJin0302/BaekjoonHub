#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,k;
    cin >> n >> k;

    vector<ll> tc(26);
    for(auto& i :tc) cin >> i;

    string s1, s2;
    cin >> s1 >> s2;
    const ll mod = 1e9+7;
    vector<ll> dp(k+1), tmp(k+1);
    for(int i = 0; i < k; i++){
        if (s2[i] == s1[0]) {
            dp[i] = 1;
            dp[k]++;
        }
    }
    for(int t = 0; t < n; t++){
        tmp = vector<ll>(k+1);
        for(int i = 0; i < k; i++){
            if (s2[i] == s1[t]){
                int nx = min(k, i + tc[(s2[i]-'A')]+1);
                tmp[nx] += dp[i];
                tmp[nx] %= mod;
            }
        }

        for(int i = 1; i <= k; i++) tmp[i] = (tmp[i]+tmp[i-1])%mod;
        swap(dp, tmp);

    }
    cout << dp[k];


}
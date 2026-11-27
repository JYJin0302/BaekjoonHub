#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[100][100];
vector<vector<ll>> base;
int n;


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        vector<ll> temp(n);
        for (auto& i :temp){
          
            cin >> i;
        }
        base.push_back(temp);
    }

    dp[0][0] = 1;

    for (ll i = 0; i < n; i++) for (ll j = 0; j < n; j++) {

        for (ll ti = 0; ti < i; ti++) {
            if(i - ti == base[ti][j])  dp[i][j] += dp[ti][j];
        }
        for (ll tj = 0; tj < j; tj++) {
            if(j-tj == base[i][tj]) dp[i][j] += dp[i][tj];
        }
    }

    cout << dp[n - 1][n - 1];

}
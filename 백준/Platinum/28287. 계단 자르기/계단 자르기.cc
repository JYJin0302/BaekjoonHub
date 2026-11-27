#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, mod;

ll dp[101], dp2[101];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> mod;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i] = (dp[i] + dp[j - 1] * dp[i - j]) % mod;
        }
    }

   // for (int i = 1; i <= n; i++) cout << dp[i] << ' ';

    dp2[0] = 0;
    dp2[1] = 0;
    dp2[2] = 1;
    for (int i = 3; i <= n; i++) {

        for (int j = 1; j <= i; j++) {
            for (int k = 1; k + j <= i+1; k++) {

                if (j + k <= i) {

                    dp2[i] += (dp[i - j] * dp[j])%mod + (dp[i - k] * dp[k]) % mod;
                    dp2[i] %= mod;

                    int mul = i - j - k;
                    dp2[i] -= ((dp[mul] * dp[j]) % mod) * dp[k] % mod;
                    dp2[i] = (dp2[i] + mod) % mod;

                    
                }
                else {
                    dp2[i] += (dp2[i - j] * dp[i - k]) % mod + (dp2[i - k] * dp[i - j]) % mod;
                    dp2[i] %= mod;
                }

                //cout << "ADD: " << curr - pv << ' ' << i << ' ' << j << ' ' << k << '\n';
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << dp2[i] << ' ';
}
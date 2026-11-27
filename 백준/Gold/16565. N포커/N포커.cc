#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int comb[53][53];
const int mod = 10007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if (n == 52) {
        cout << 1;
        return 0;
    }


    comb[1][0] = 1;
    comb[1][1] = 1;
    for (int i = 2; i <= 52; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i-1][j - 1]) % mod;
        }
    }

    int ans = 0;
    
    for (int i = 1; i <= n / 4; i++) {
        // i 개의 포카드 뽑음

        int tmp = comb[13][i] * comb[52 - 4 * i][n - i*4] % mod;
        
        if (i % 2 == 1) ans = (ans + tmp) % mod;
        else ans = (ans + mod - tmp) % mod;
    }

    cout << ans;
}
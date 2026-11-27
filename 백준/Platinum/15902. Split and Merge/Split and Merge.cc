#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define x first
#define y second

const ll mod = 1e9 + 7;
ll dp[3010][3010];
ll comb[3010][3010];
ll val[3010];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, n1, n2;
    cin >> n;

    cin >> n1;
    vector<int> A(n1);
    for (auto& i : A) cin >> i;
    
    cin >> n2;
    vector<int> B(n2);
    for (auto& i : B) cin >> i;

    dp[1][1] = 1;
    dp[2][1] = 0;
    dp[2][2] = 1;

    for (int i = 2; i < 3000; i++) {
        for (int j = 1; j <= i; j++) {

            if ((i & 1) == 0) {
                // 1~j 까지 들어감
                dp[i + 1][1] += dp[i][j];
                dp[i + 1][1] % mod;
                dp[i + 1][j + 1] -= dp[i][j];
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] % mod + mod) % mod;
            }
            else {
                // j+1~i+1 까지 들어감
                dp[i + 1][j + 1] += dp[i][j];
                dp[i + 1][j + 1] %= mod;
            }
        }

        for (int j = 1; j <= i+1; j++) {
            dp[i + 1][j] += dp[i+1][j-1];
            dp[i + 1][j] = (dp[i+1][j] % mod + mod) % mod;
        }
    }

    for (int i = 1; i <= 3000; i++) {
        for (int j = 1; j <= i; j++) {
            val[i] += dp[i][j];
            val[i] %= mod;
        }
    }

    comb[1][0] = 1;
    comb[1][1] = 1;
    for (int i = 2; i <= 3000; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
        }
    }

    int ix1 = 0, ix2 = 0;

    int ansv = 0;
    vector<int> ans;
    while (ix1 < n1 && ix2 < n2) {

        if (A[ix1] == B[ix2]) {
            ix1++, ix2++;
        }
        else {

            int tx1 = ix1, tx2 = ix2, cnt = 0;
            int val1 = A[ix1], val2 = B[ix2];
            tx1++, tx2++;
            while (val1 != val2) {
                if (val1 > val2) {
                    val2 += B[tx2];
                    tx2++;
                }
                else {
                    val1 += A[tx1];
                    tx1++;
                }
                cnt++;
            }
            ans.push_back(cnt);
            ansv += cnt;

            ix1 = tx1;
            ix2 = tx2;
        }

    }

    cout << ansv << ' ';
    ll res = 1;

    for (auto i : ans) {
        res = res * comb[ansv][i] % mod;
        res = res * val[i] % mod;
        ansv -= i;
    }

    cout << res;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) x.begin(), x.end()
#define mp make_pair
#define x first
#define y second

const int mod = 1e9 + 7;

vector<ll> goSolve(char a, char b, char c, vector<ll> dp, bool noZero = 0) {
    vector<ll> res(2);

    if (a == '?') swap(a, b);
    if (a == '?') {
        for (int na = noZero; na <= 9; na++) {
            for (int nb = noZero; nb <= 9; nb++) {
                int nval = na + nb;
                if (c == '?' || nval % 10 == c - '0') {
                    if (nval >= 10) (res[1] += dp[0]) %= mod;
                    else (res[0] += dp[0]) %= mod;
                }
                nval = na + nb + 1;
                if (c == '?' || nval % 10 == c - '0') {
                    if (nval >= 10) (res[1] += dp[1]) %= mod;
                    else (res[0] += dp[1]) %= mod;
                }
            }
        }
    }
    else if (b == '?') {
        int na = a - '0';
        for (int nb = noZero; nb <= 9; nb++) {
            int nval = na + nb;
            if (c == '?' || nval % 10 == c - '0') {
                if (nval >= 10) (res[1] += dp[0]) %= mod;
                else (res[0] += dp[0]) %= mod;
            }
            nval = na + nb + 1;
            if (c == '?' || nval % 10 == c - '0') {
                if (nval >= 10) (res[1] += dp[1]) %= mod;
                else (res[0] += dp[1]) %= mod;
            }
        }
    }
    else {
        int na = a - '0';
        int nb = b - '0';
        int nval = na + nb;
        if (c == '?' || nval % 10 == c - '0') {
            if (nval >= 10) (res[1] += dp[0]) %= mod;
            else (res[0] += dp[0]) %= mod;
        }
        nval = na + nb + 1;
        if (c == '?' || nval % 10 == c - '0') {
            if (nval >= 10) (res[1] += dp[1]) %= mod;
            else (res[0] += dp[1]) %= mod;
        }
    }

    return res;
}
void solve() {
    
    string a, b, c;
    cin >> a;
    if (a == "0") {
        exit(0);
    }
    cin >> b >> c;

    int n = a.size();
    vector<ll> dp(2); // no carry, carry
    dp[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        dp = goSolve(a[i], b[i], c[i], dp, (i == 0));
    }

    cout << dp[0] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1) solve();

    return 0;
}
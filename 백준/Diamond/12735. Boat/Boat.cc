#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9 + 7;
ll fastPow(ll b, ll ex) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}

vector<int> num;
int getIdx(int x) {
    return lower_bound(all(num), x) - num.begin();
}

ll dp[1010][2010];
ll inv[101010];

void solve() {

    inv[1] = 1;
    for (int i = 2; i <= 500; i++) {
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    }

    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for (auto& i : A) {
        cin >> i.x >> i.y;
        i.x--;
        num.push_back(i.x);
        num.push_back(i.y);
    }
    num.push_back(0);
    sort(all(num));
    num.erase(unique(all(num)), num.end());

    int sz = num.size();
    for (int i = 0; i < sz; i++) {
        dp[0][i] = 1;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        auto& [a, b] = A[i - 1];
        a = getIdx(a) + 1;
        b = getIdx(b);

        for (int j = a; j <= b; j++) {
            int len = num[j] - num[j - 1];

            ll v1 = len;
            int cnt = 1;

            for (int k = i - 1; k >= 0; k--) {
                dp[i][j] += dp[k][j - 1] * v1 % mod;
                if (A[k - 1].x <= j && A[k - 1].y >= j) {
                    cnt++;
                    v1 = v1 * (len + cnt - 1) % mod;
                    v1 = v1 * inv[cnt] % mod;
                }
            }
        }

        for (int j = 1; j < sz; j++) {
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= mod;
        }

        ans = (ans + dp[i][sz - 1]) % mod;
    }
    cout << ans << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
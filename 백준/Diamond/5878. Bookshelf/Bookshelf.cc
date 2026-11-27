#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

ll H[101010];
ll W[101010];
ll sW[101010];

void solve() {

    ll n, len = 0;
    cin >> n >> len;
    for (int i = 1; i <= n; i++) {
        cin >> H[i] >> W[i];
        sW[i] = W[i] + sW[i - 1];
    }

    vector<ll> dp(n + 1);
    multiset<ll> ms;

    deque<pair<int, int>> hList; // 구간 [a, b] : 높이 = H[b]

    for (int i = 1; i <= n; i++) {
        int tl = i;
        while (!hList.empty()) {
            auto [a, b] = hList.back();
            if (H[b] < H[i]) {
                hList.pop_back();
                ms.erase(ms.find(dp[a - 1] + H[b]));
                tl = a;
            }
            else break;
        }

        if (hList.empty()) {
            hList.push_back(mp(tl, i));
            ms.insert(dp[tl - 1] + H[i]);
        }
        else {
            auto [a, b] = hList.back();
            if (H[b] == H[i]) {
                hList.back().second = i;
            }
            else {
                hList.push_back(mp(tl, i));
                ms.insert(dp[tl - 1] + H[i]);
            }
        }

        while (!hList.empty()) {
            auto [a, b] = hList.front();
            if (sW[i] - sW[a - 1] > len) {
                // cout << "Erase: " << a << ' ' << b << '\n';
                hList.pop_front();
                ms.erase(ms.find(dp[a - 1] + H[b]));

                if (a == b) {}
                else {
                    hList.push_front(mp(a + 1, b));
                    ms.insert(dp[a] + H[b]);
                }
            }
            else break;
        }
        dp[i] = *ms.begin();
    }
    cout << dp[n] << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
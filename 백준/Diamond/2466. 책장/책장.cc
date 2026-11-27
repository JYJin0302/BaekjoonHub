#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int H[101010];
int W[101010];
int sW[101010];
const int INF = 1e9 + 10;

void solve() {

    int n, l = 0, r = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> W[i] >> H[i];
        sW[i] = W[i] + sW[i - 1];
        l = max(l, W[i]);
    }
    r = sW[n];
    int ans = r;
    while (l <= r) {
        int m = (l + r) >> 1;
        //cout << string(10, '-') << "Go: " << m << '\n';
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[n] = INF;
        multiset<int> ms;

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
                if (sW[i] - sW[a - 1] > m) {
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

            /*for (auto [a, b] : hList) cout << '{' << a << ", " << b << "} ";
            cout << '\n';
            for (auto f : ms) cout << f << ' ';
            cout << '\n';*/

            dp[i] = *ms.begin();
            if (dp[i] > m) break;
        }

        /*for (auto f : dp) cout << f << ' ';
        cout << '\n';*/

        if (dp[n] <= m) {
            ans = m;
            r = m - 1;
        }
        else l = m + 1;

    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
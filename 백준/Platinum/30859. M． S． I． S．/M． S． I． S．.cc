#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.first;
    for (auto& i : A) cin >> i.second;

    sort(A.begin(), A.end());

    vector<int> C(n), num = { 0 };
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += A[i].first + A[i].second;
        C[i] = min(A[i].first, A[i].second);
    }

    vector<int> dp(50001, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int minV = 1e9;
        for (auto f : num) {
            if (f < A[i].second) {
                minV = min(minV, dp[f]);   
            }
            dp[f] += C[i];
        }
        dp[A[i].second] = minV;
        num.push_back(A[i].second);

        /*for (auto f : num) cout << '{' << f << ", " << dp[f] << "} ";
        cout << '\n';*/
    }

    cout << ans - *min_element(dp.begin(), dp.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}

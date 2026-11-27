#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second - a.first == b.second - b.first) {
        return a.first < b.first;
    }
    return a.second - a.first < b.second - b.first;
}

int dp[202][202];

void solve() {

    int n, p;
    cin >> n >> p;

    vector<pair<int, int>> A(n), B;
    for (auto& i : A) cin >> i.first >> i.second;
    sort(A.begin(), A.end(), cmp);

    vector<int> C;

    for (int i = 0; i < n; i++) {
        int a, b;
        tie(a, b) = A[i];

        bool ok = 0;
        for (auto f : B) {
            if (f.first >= a && f.second <= b) {
                ok = 1;
            }
        }
        if (ok) C.push_back(b - a);
        else B.push_back(A[i]);
    }
    sort(B.begin(), B.end());
    sort(C.rbegin(), C.rend());

     /*cout << "B: \n";
     for (auto f : B) {
         cout << f.first << ' ' << f.second << '\n';
     }*/

    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 1; i <= B.size(); i++) {
        int a, b;
        tie(a, b) = B[i - 1];

        for (int j = 1; j <= n; j++) {

            for (int k = 1; k <= p; k++) {
                if (dp[i - j][k - 1] >= 0) {
                    dp[i][k] = max(dp[i][k], dp[i - j][k - 1] + b - a);
                }
            }

            if (j >= i) break;
            b = min(b, B[i - j - 1].second);
            a = max(a, B[i - j - 1].first);

            if (a >= b) break;
        }
        for (int j = 1; j <= p; j++) {
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);

           // cout << dp[i][j] << ' ';
        }
         //cout << '\n';


    }
    int ti = B.size();
    int ans = dp[ti][p];

    int cur = 0;
    for (int i = 0; i < C.size(); i++) {
        cur += C[i];
        if (dp[ti][p - i - 1] >= 0) {
            ans = max(ans, dp[ti][p - i - 1] + cur);
        }
    }
    cout << ans;

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    solve();
}
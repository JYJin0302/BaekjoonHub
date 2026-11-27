#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A, B;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x != 0) A.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x != 0) B.push_back(x);
    }

    int na = A.size();
    int nb = B.size();

    vector<vector<int>> dp(na + 1, vector<int>(nb + 1, -1e9)), tmp;
    dp[0][0] = 0;
    tmp = dp;

    for (int i = 1; i <= n; i++) {

        for (int j = 0; j <= A.size(); j++) {
            for (int k = 0; k <= B.size(); k++) {
                tmp[j][k] = max(tmp[j][k], dp[j][k]);
                if (j > 0) tmp[j][k] = max(tmp[j][k], dp[j - 1][k]);
                if (k > 0) tmp[j][k] = max(tmp[j][k], dp[j][k - 1]);
                if (j > 0 && k > 0) tmp[j][k] = max(tmp[j][k], dp[j - 1][k - 1] + A[j - 1] * B[k - 1]);
            }
        }
        swap(tmp, dp);
    }

    cout << dp[A.size()][B.size()];
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int mod = 1e9 + 7;
vector<vector<vector<ll>>> dp;
vector<vector<ll>> mult(vector<vector<ll>> a, vector<vector<ll>> b) {

    vector<vector<ll>> res(8, vector<ll>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k < 8; k++) {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}


int main() {

    int n;
    cin >> n;

    dp.push_back(
        {
            {0, 1, 0, 1, 0, 0, 0, 0},
            {1, 0, 1, 1, 0, 0, 0, 0},
            {0, 1, 0, 1, 1, 1, 0, 0},
            {1, 1, 1, 0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 1, 1, 0},
            {0, 0, 1, 1, 1, 0, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 1},
            {0, 0, 0, 0, 0, 1, 1, 0}
        }
    );
    n--;
    int size = 2;
    while (size <= n) {
        size *= 2;
        dp.push_back(mult(dp.back(), dp.back()));
    }
    
    size /= 2;
    int ind = dp.size() - 1;
    

    vector<vector<ll>> ans = dp[0];
    while (n) {
        if (size <= n) {
            ans = mult(ans, dp[ind]);
            n -= size;
        }

        ind--;
        size /= 2;
    }

    cout << ans[0][0];
}
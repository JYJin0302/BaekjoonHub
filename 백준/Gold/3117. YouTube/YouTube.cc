#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;

    int size = log2(m);
    vector<int> A(n);
    for (auto& i : A) cin >> i;
    m--;

    dp = vector<vector<int>> (size+1, vector<int>(k+1));
    for (int i = 1; i <= k; i++) cin >> dp[0][i];

    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    for (int i : A) {

        int temp = m;
        for (int j = 0; temp; j++) {
            if (temp & 1) i = dp[j][i];
            temp /= 2;
        }

        cout << i << ' ';
    }

}
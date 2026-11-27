#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main() {

    int n;
    cin >> n;

    int ans = 0;
    vector<int> A = { 0 };
    int size = 1;
    while (A.back() < n) {
        size++;
        A.push_back(size * (size - 1) / 2 + A.back());
    }

    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int k : A) {
            if (i < k) break;
            dp[i] = min(dp[i], dp[i - k] + 1);
        }
    }

    cout << dp[n];
}
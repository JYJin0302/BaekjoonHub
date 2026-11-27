#include <bits/stdc++.h>
using namespace std;
using ll = long long;

priority_queue<pair<int, int>> pq[400040];
int dp[100001];

void solve() {

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> A(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'Y') A[i+1] = 1;
        else A[i + 1] = -1;
        A[i + 1] += A[i];
    }

    
    pq[n].push({ 0, 0 });
    for (int i = 1; i <= n; i++) {
        int val = A[i];
        val += n;

        int mx = i;
        for (int j = val - 1; j <= val + 1; j++) {
            while (!pq[j].empty() && i - pq[j].top().second > k) pq[j].pop();
            if (!pq[j].empty()) mx = min(mx, -pq[j].top().first + 1);
        }

        dp[i] = mx;
        pq[val].push({ -mx, i });
    }
    //for (int i = 1; i <= n; i++) cout << dp[i] << ' ';
    cout << dp[n];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}
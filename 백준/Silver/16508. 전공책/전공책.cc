#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main() {

    string s;
    cin >> s;

    vector<int> target(26);
    for (char c : s) target[c - 'A']++;

    int n;
    cin >> n;

    vector<int> cost(n);
    vector<vector<int>> A(n, vector<int>(26));

    for (int i = 0; i < n; i++) {
        int x;
        string s;
        cin >> x >> s;
        cost[i] = x;
        for (char k : s) {
            A[i][k - 'A']++;
        }
    }

    int ans = INF;
    vector<int> cnt;

    for (int i = 1; i < (1 << n); i++) {
        cnt = vector<int>(26);
        int tcost = 0;

        for (int k = 0; k < n; k++) {
            if (i & (1 << k)) {
                tcost += cost[k];
                for (int j = 0; j < 26; j++) {
                    cnt[j] += A[k][j];
                }
            }
        }

        bool ok = 1;
        for (int j = 0; j < 26; j++) {
            if (cnt[j] < target[j]) ok = 0;
        }

        if (ok) ans = min(ans, tcost);
    }

    if (ans == INF) ans = -1;
    cout << ans;
}
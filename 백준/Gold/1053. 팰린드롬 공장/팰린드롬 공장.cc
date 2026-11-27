#include <bits/stdc++.h>
using namespace std;

string s;
int dp[50][50];

int solve(int l = 0, int r = s.size() - 1) {
    if (l >= r) return dp[l][r] = 0;
    if (dp[l][r] != -1) return dp[l][r];

    if (s[l] == s[r]) {
        return dp[l][r] = solve(l + 1, r - 1);
    }

    return dp[l][r] = min({ solve(l + 1, r), solve(l, r - 1), solve(l + 1, r - 1) }) + 1;
}

int main() {

    string b;
    cin >> b;
    
    if (b.size() == 1){
        cout << 0;
        return 0;
    }
    
    int ans = 100000;
    for (int x = 0; x < 50; x++) {
        for (int y = 0; y < 50; y++) {
            dp[x][y] = -1;
        }
    }
    s = b;
    ans = min(ans, solve());

    for (int i = 0; i < b.size() - 2; i++) {
        for (int j = i + 1; j < b.size() - 1; j++) {
            if (b[i] == b[j]) continue;

            for (int x = 0; x < 50; x++) {
                for (int y = 0; y < 50; y++) {
                    dp[x][y] = -1;
                }
            }
            s = b;
            swap(s[i], s[j]);

            ans = min(ans, solve() + 1);
        }
    }

    cout << ans;
}
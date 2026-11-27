#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int dp[201][201][201];

int solve(int w, int l, int h) {
    if (w > l) swap(w, l);
    if (l > h) swap(l, h);
    if (w > l) swap(w, l);
    
    if (dp[w][l][h] != -1) return dp[w][l][h];
    if (w == h) return dp[w][l][h] = 0;
    if (w == 1) return dp[w][l][h] = l * h - 1;

    int temp = INF;
    for (int i = 1; i <= w/2; i++) {
        temp = min(temp, solve(i, l, h) + solve(w - i, l, h) + 1);
    }
    for (int j = 1; j <= l/2; j++) {
        temp = min(temp, solve(w, j, h) + solve(w, l - j, h) + 1);
    }
    for (int k = 1; k <= h/2; k++) {
        temp = min(temp, solve(w, l, k) + solve(w, l, h - k) + 1);
    }

    return dp[w][l][h] = temp;
}


int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int t;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while (t--) {
        int w, l, h;
        cin >> w >> l >> h;        
        cout << solve(w, l, h) + 1 << '\n';
    }
}
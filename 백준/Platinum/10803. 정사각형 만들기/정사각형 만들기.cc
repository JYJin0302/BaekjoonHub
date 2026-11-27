#include <bits/stdc++.h>
using namespace std;

int dp[330][330];

int solve(int l, int r) {
    if (l > r) swap(l, r);
    if (l == 0) return 0;

    if (dp[l][r] != 0) return dp[l][r];
    if (l == r) return 1;

    if (r > 320) {
        int cnt = 0;
        while (r > 320) {
            r -= l;
            cnt++;
        }
        return cnt + solve(l, r);
    }

    int res = l * r;
    for (int i = 1; i * 2 <= l; i++) {
        res = min(res, solve(i, r) + solve(l - i, r));
    }
    for (int i = 1; i * 2 <= r; i++) {
        res = min(res, solve(l, i) + solve(l, r - i));
    }
    return dp[l][r] = res;
}

int main() {

    int n, m;
    cin >> n >> m;

    cout << solve(n, m);

}
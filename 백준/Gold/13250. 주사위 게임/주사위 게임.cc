#include <bits/stdc++.h>
using namespace std;
using ll = long long;

long double dp[1000001];

long double solve(int x) {
    if (x <= 0) return 0;
    if (dp[x] != 0) return dp[x];

    long double res = 0;
    for (int i = 1; i <= 6; i++) {
        res += (solve(x - i) +1)/ 6 ;
    }
    return dp[x] = res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10);

    int n;
    cin >> n;

    cout << solve(n);

}
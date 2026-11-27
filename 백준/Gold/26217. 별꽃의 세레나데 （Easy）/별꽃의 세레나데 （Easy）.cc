#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

long double dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << setprecision(10) << fixed;
    int n;
    cin >> n;

    long double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1.0 * n / i;
    }
    cout << ans;
}
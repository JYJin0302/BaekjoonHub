#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


bool isY(int x) {
    if (x % 400 == 0) return 1;
    if (x % 4 == 0 && x % 100 != 0) return 1;
    return 0;
}

int dM[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int getDiff(int y, int m, int d) {
    int by = 1990;
    int bm = 1;
    int bd = 1;
    int res = 0;
    for (int i = by; i < y; i++) {
        if (isY(i)) res += 366;
        else res += 365;
    }

    for (int i = 1; i < m; i++) {
        res += dM[i];
        if (i == 2 && isY(y)) res++;
    }
    res += d;

    return res;

}

void solve() {

    int Y1, M1, D1;
    int Y2, M2, D2;
    cin >> Y1 >> M1 >> D1;
    cin >> Y2 >> M2 >> D2;
    int diff = getDiff(Y2, M2, D2) - getDiff(Y1, M1, D1);
   // cout << diff << '\n';
    int t, n;
    cin >> t >> n;

    vector<int> dp(t + 10);
    for (int i = 0; i < n; i++) {

        int a, b, c;
        cin >> a >> b >> c;
        if (a == 3) {
            c *= 30;
        }
        for (int j = t; j >= b; j--) {
            dp[j] = max(dp[j], dp[j - b] + c);
        }

       /* for (auto f : dp) cout << f << ' ';
        cout << '\n';*/
    }

    diff -= *max_element(all(dp));

    cout << abs(diff);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
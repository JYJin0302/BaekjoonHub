#include<bits/stdc++.h>
using ll = long long;
using namespace std;
using ld = long double;

ld fastPow(ld base, int ex) {
    ld res = 1;
    while (ex) {
        if (ex & 1) res *= base;
        base = base * base;
        ex >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15);

    int n, i, k;
    cin >> n >> i >> k;
    vector<ld> ans(n+10);

    for (int j = 1; j <= n; j++) {
       //cout << "CURR: " << j << '\n';;
        ld v1 = 1.0 * j / n, v2 = 1.0 * (j-1.0)/n;
        ld val = fastPow(v1, k) - fastPow(v2, k);
       // cout << "?";
        if (j < i) {
            ans[i] += val;
            ans[i + 1] -= val;
        }
        else {
            ans[1] += val/j;
            ans[j + 1] -= val/j;
        }
    }

    ld res = 0;
    for (int i = 1; i <= n; i++) {
        ans[i] += ans[i - 1];
       // cout << ans[i] << ' ';
    }
  //  cout << '\n';
    for (int i = 1; i <= n; i++) {
        res += i * ans[i];
    }
    cout << res;

}

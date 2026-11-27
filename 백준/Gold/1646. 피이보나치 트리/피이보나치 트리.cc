#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, a, b;
    cin >> n >> a >> b;

    if (a == b) return 0;

    vector<ll> f(n + 1);
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2] + 1;

    int s = 1;

    int idx = n;
    while (idx > 1 && s != a && s != b) {
        if (s + f[idx - 2] + 1 <= min(a, b)) {
            s += f[idx - 2] + 1;
            idx--;
        }
        else if (s + f[idx - 2] + 1 > max(a, b)) {
            idx -= 2;
            s++;
        }
        else break;
    }

    string ans;

    int ts = s, tdx = idx;
    while (ts != a) {
        if (ts + f[tdx - 2] + 1 <= a) {
            ts += f[tdx - 2] + 1;
            tdx--;
            ans.push_back('U');
        }
        else {
            tdx -= 2;
            ts++;
            ans.push_back('U');
        }
    }

    ts = s, tdx = idx;
    while (ts != b) {
        if (ts + f[tdx - 2] + 1 <= b) {
            ts += f[tdx - 2] + 1;
            tdx--;
            ans.push_back('R');
        }
        else {
            tdx -= 2;
            ts++;
            ans.push_back('L');
        }
    }

    cout << ans;

}
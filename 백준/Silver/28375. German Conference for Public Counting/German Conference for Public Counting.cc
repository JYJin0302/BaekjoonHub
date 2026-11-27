#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) x.begin(), x.end()
#define mp make_pair


void solve() {

    ll n;
    cin >> n;
    if (n <= 9) {
        cout << n + 1;
        return;
    }

    int ans = 0;
    string s = to_string(n);
    ans += s.size() - 1;
    for (int i = 1; i <= 9; i++) {
        ll v = i;
        int cnt = 1;
        while (v <= n) {
            v = v * 10 + i;
            cnt++;
        }
        ans += cnt - 1;
    }
    cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
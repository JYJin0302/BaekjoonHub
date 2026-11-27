#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    string s;
    cin >> s;
    int ans = 10;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) ans += 5;
        else ans += 10;
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
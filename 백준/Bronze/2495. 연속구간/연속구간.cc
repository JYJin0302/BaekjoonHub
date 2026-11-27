#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


 

void solve() {

    string s;
    cin >> s;

    int cnt = 1, ans = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 3;
   // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n;
    cin >> n;

    int ans = 0;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (cnt[s] >= 1 && (i - cnt[s]) < cnt[s]) ans++;
        cnt[s]++;
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
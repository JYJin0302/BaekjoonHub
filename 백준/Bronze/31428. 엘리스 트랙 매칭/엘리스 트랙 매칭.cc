#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n;
    cin >> n;

    map<char, int> cnt;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        cnt[c]++;
    }

    char c;
    cin >> c;
    cout << cnt[c] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[101];
int cnt[4];

int getVal() {
    return cnt[0] + 3 * cnt[1] + 9 * cnt[2] + 27 * cnt[3];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<char, int> mp;
    mp['T'] = 0;
    mp['G'] = 1;
    mp['F'] = 2;
    mp['P'] = 3;

    string s;
    cin >> s;
    ll ans = 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cnt[mp[s[i]]] = (cnt[mp[s[i]]] + 1) % 3;
        int cv = getVal();
        ans += dp[cv];
        dp[cv]++;
    }
    cout << ans;
}
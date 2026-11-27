#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll b;
    cin >> b;
    while (b != 0) {

        string s, m;
        cin >> s >> m;

        ll mod = 0;
        for (char i : m) {
            mod = mod * b + (i - '0');
        }

        ll num = 0;
        for (char i : s) {
            num = num * b + (i - '0');
            num %= mod;
        }

        if (num == 0) cout << "0\n";
        else {
            string ans = "";
            while (num) {
                ans += char('0' + num % b);
                num /= b;
            }

            reverse(ans.begin(), ans.end());
            cout << ans << '\n';
        }
        cin >> b;
    }
}
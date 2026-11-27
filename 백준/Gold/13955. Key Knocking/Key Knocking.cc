#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char rev(char c) {
    return char('0' + '1' - c);
}

void solve() {

    string s;
    cin >> s;

    int n = s.size();

    vector<int> ans;
    if (s[0] == s[1] && s[1] == s[2]) {
        ans.push_back(2);
        s[1] = rev(s[1]);
        s[2] = rev(s[2]);
    }
    for (int i = 3; i < n; i += 3) {

        bool x1 = s[i] != s[i - 1];
        bool x2 = s[i + 1] != s[i];
        bool x3 = s[i + 2] != s[i + 1];

        int cnt = x1 + x2 + x3;
        if (cnt >= 2) {}
        else if (cnt == 0) {
            ans.push_back(i + 1);
            s[i] = rev(s[i]);
            s[i + 1] = rev(s[i + 1]);
        }
        else if (x1) {
            ans.push_back(i + 2);
            s[i+2] = rev(s[i+2]);
            s[i + 1] = rev(s[i + 1]);
        }
        else if (x2) {
            ans.push_back(i + 1);
            s[i] = rev(s[i]);
            s[i + 1] = rev(s[i + 1]);
        }
        else {
            ans.push_back(i + 2);
            s[i + 2] = rev(s[i + 2]);
            s[i + 1] = rev(s[i + 1]);
        }
    }

    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) {
        solve();

    }

}
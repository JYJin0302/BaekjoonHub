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

    vector<string> res;
    string ts;
    cin >> ts;
    string pre;
    for (int i = 0; i < ts.size(); i++) {
        char c = ts[i];

        if (c == '-' || c == '+' || c == '0') pre += c;
        else {
            if (!pre.empty()) res.push_back(pre);
            pre = c;
        }
    }
    res.push_back(pre);

    pre = "??";
    for (int i = 0; i < res.size(); i++) {
        string s = res[i];
        if (s.size() == 1) s += '0';
        if (s[0] == 'C') {
            cout << "B";
        }
        else if (s[0] == 'B' && s[1] != '+') {
            if (!i || pre[0] == 'C') cout << "D";
            else cout << "B";
        }
        else if (s[0] == 'B' || s[1] == '-') {
            if (!i || pre[0] == 'C' || (pre[0] == 'B' && pre[1] != '+')) cout << 'P';
            else cout << 'D';
        }
        else if (s[1] != '+') {
            if (i && pre[0] == 'A' && pre[1] != '-') cout << "P";
            else cout << "E";
        }
        else cout << "E";
        pre = s;
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
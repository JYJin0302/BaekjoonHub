#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

string add(string s1, string s2) {
    reverse(all(s1));
    reverse(all(s2));

    string ans;
    int pv = 0;
    for (int i = 0; i < max(s1.size(), s2.size()); i++) {
        int nv = pv;
        pv = 0;
        if (i < s1.size()) nv += s1[i] - '0';
        if (i < s2.size()) nv += s2[i] - '0';
        if (nv >= 10) nv -= 10, pv++;
        ans += char('0' + nv);
    }
    if (pv) ans += '1';
    reverse(all(ans));
    return ans;
}

string mult(string s1, int v) {
    string res = "0";
    for (int i = 0; i < v; i++) res = add(res, s1);

    return res;
}
string mult(string s1, string s2) {
    string res = "0";
    int sz = s2.size();
    for (int i = 0; i < sz; i++) {
        string tmp = mult(s1, s2[i] - '0');
        tmp += string(sz - i - 1, '0');
        res = add(res, tmp);
    }
    return res;
}

void solve() {

    string s1, s2;
    cin >> s1 >> s2;

    cout << s1 << '\n' << s2 << '\n';
    for (int i = s2.size() - 1; i >= 0; i--) {
        cout << mult(s1, s2[i] - '0') << '\n';
    }
    cout << mult(s1, s2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
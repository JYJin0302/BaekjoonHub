#include <bits/stdc++.h>
using namespace std;

string nextState(string s) {

    int n = s.size();
    string res(n, '0');

    for (int i = 0; i < n; i++) {
        int t = 0;
        if (i + 1 < n && s[i + 1] == '1') t ^= 1;
        if (i > 0 && s[i - 1] == '1') t ^= 1;
        res[i] = char('0' + t);
    }
    return res;
}

bool live(string s) {

    int n = s.size();

    bool ok = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ok = 0;
    }
    if (ok) return 0;
    if (n % 2 == 0) return 1;
    string ts, ts2;
    for (int i = 1; i < n; i += 2) ts += s[i];

    s = nextState(s);
    for (int i = 1; i < n; i += 2) ts2 += s[i];

    return live(ts) || live(ts2);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {

        string s;
        cin >> s;

        if (live(s)) cout << "LIVES\n";
        else cout << "DIES\n";
    }
}
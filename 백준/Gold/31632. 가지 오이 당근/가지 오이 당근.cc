#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    bool draw = 0;
    for (auto f : s2) if (f == 'D') draw = 1;

    if (draw && s2 != string(n, 'D')) {
        cout << "NO\n";
        return;
    }

    if (draw) {
        // all same
        string t = "GOD";
        for (int j = 0; j < 3; j++) {
            bool ok = 1;
            for (int i = 0; i < n; i++) {
                if (s1[i] == t[j] || s1[i] == '?') {}
                else ok = 0;
            }
            if (ok) {
                cout << "YES\n" << string(n, t[j]) << '\n';
                return;
            }
        }
        // every occurance
        int cnt = 0;
        vector<bool> chk(3);
        for (int i = 0; i < n; i++) {
            if (s1[i] == '?') cnt++;
            else {
                if (s1[i] == 'G') chk[0] = 1;
                else if (s1[i] == 'O') chk[1] = 1;
                else chk[2] = 1;
            }
        }

        int nd = 0;
        for (int j = 0; j < 3; j++) if (!chk[j]) nd++;

        if (cnt >= nd) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (s1[i] == '?') {
                    int k = 0;
                    for (k = 0; k < 3; k++) {
                        if (!chk[k]) {
                            cout << t[k];
                            chk[k] = 1;
                            break;
                        }
                    }
                    if (k == 3) cout << t[0];
                }
                else cout << s1[i];
            }
            cout << '\n';
        }
        else cout << "NO\n";
        return;
    }

    string t = "GOD";
    for (int j = 0; j < 3; j++) {
        char w = t[j];
        char l = t[(j + 1) % 3];

        vector<bool> chk(2);

        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (s2[i] == 'W') {
                if (s1[i] == w || s1[i] == '?') { chk[0] = 1; }
                else ok = 0;
            }
            else {
                if (s1[i] == l || s1[i] == '?') { chk[1] = 1; }
                else ok = 0;
            }
        }
        if (chk[0] && chk[1]) {}
        else ok = 0;

        if (ok) {
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                if (s2[i] == 'W') cout << w;
                else cout << l;
            }
            cout << '\n';
            return;
        }
    }
    cout << "NO\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {

        string s;
        cin >> s;

        ll pA = 0, pB = 0;

        int n = s.size();
        int ix = n - 1;
        while (ix >= 0 && s[ix] == '.') ix--;

        char curr = s[ix];
        ll cnt = 1;
        ix--;
        while (ix >= 0) {
            if (s[ix] == '.') {
                if (curr == 'W') pA += cnt;
                else if (curr == 'B') pB += cnt;
            }
            else if (s[ix] == curr) {
                cnt++;
            }
            else {
                if (cnt >= 1) {
                    cnt = 0;
                    curr = '?';
                }
                else {
                    cnt = 1;
                    curr = s[ix];
                }
            }
            ix--;

            //cout << ix+1 << ' ' << pA << ' ' << pB << ' ' << cnt << ' ' << curr << '\n';
        }

        if (pA > pB) cout << "WHITE\n";
        else cout << "BLACK\n";
    }
}
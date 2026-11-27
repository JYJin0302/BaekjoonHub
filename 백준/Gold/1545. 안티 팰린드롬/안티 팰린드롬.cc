#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int n = s.size();
    vector<int> cnt(26);
    for (char c : s) cnt[c - 'a']++;

    string ans;
    for (int i = 0; i < 26; i++) {
        ans += string(cnt[i], 'a' + i);
    }

    int fi = (n + 1) / 2;
    while (fi < n) {
        if (ans[fi] == ans[n - 1 - fi]) break;
        fi++;
    }

    if (fi != n) {

        int di = fi;
        while (di != n && ans[fi] == ans[n - 1 - di]) di++;

        int tdi = di;
        di = fi;
        while (di != n && ans[fi] == ans[di]) di++;

        int cc = tdi - fi;
        for (int i = 0; i < cc; i++) {

            int ki = di + i;

            if (ki >= n) break;
            while (ki != fi + i) swap(ans[ki], ans[ki - 1]), ki--;
            
        }

        for (int i = (n + 1) / 2; i < n; i++) {
            if (ans[i] == ans[n - 1 - i]) {
                cout << -1;
                return 0;
            }
        }

    }
    cout << ans;
}
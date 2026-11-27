#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    vector<int> cnt(26);
    for (char c : s) cnt[c - 'A']++;

    int cnt_odd = 0;
    int ci = -1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] % 2 == 1) cnt_odd++, ci = i;
    }

    if (cnt_odd > 1) cout << "I'm Sorry Hansoo";
    else {
        for (int i = 0; i < 26; i++) {
            cout << string(cnt[i] / 2, 'A' + i);
        }

        if (ci != -1) cout << char('A' + ci);

        for (int i = 25; i >= 0; i--) {
            cout << string(cnt[i] / 2, 'A' + i);
        }
    }
}
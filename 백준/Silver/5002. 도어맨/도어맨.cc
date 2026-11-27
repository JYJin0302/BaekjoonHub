#include <bits/stdc++.h>
using namespace std;

// 뒤에 있는 사람 먼저
int main() {

    int x;
    cin >> x;
    string s;
    cin >> s;

    int fir = 0, sec = 1;
    int w = 0, m = 0;
    while (fir < s.size()) {
        bool first = 1, second = 1;
        if (s[fir] == 'W') {
            if (abs(w + 1 - m) > x) first = 0;
        }
        else {
            if (abs(m + 1 - w) > x) first = 0;
        }
        if (sec == s.size()) {
            if (first) {
                (s[fir] == 'W' ? w : m)++;
                fir = sec;
                sec = fir + 1;
                continue;
            }
            else break;
        }

        if (s[sec] == 'W') {
            if (abs(w + 1 - m) > x) second = 0;
        }
        else {
            if (abs(m + 1 - w) > x) second = 0;
        }
        if (!second && !first) {
            break;
        }

        if (second) {
            (s[sec] == 'W' ? w : m)++;
            sec++;
            continue;
        }
        else if (first) {
            (s[fir] == 'W' ? w : m)++;
            fir = sec;
            sec = fir + 1;
            continue;
        }
    }
    cout << w + m;

}
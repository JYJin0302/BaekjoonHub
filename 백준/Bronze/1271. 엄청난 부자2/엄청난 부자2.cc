#include <bits/stdc++.h>
using namespace std;

string ans;

string set_int(string s) {
    int idx = 0;
    while (idx < s.size() && s[idx] == '0') idx++;

    if (idx == s.size()) return "0";
    return s.substr(idx, s.size());
}

string divide(string s1, string s2) {
    s1 = set_int(s1);
    reverse(s1.begin(), s1.end());
    
    s2 = set_int(s2);
    reverse(s2.begin(), s2.end());

    if (s2.size() > s1.size()) {
        ans += '0';
        reverse(s1.begin(), s1.end());
        return s1;
    }

    int num = 0;
    string temp;
    bool minus = 0;
    while (!minus) {

        // try s1 - s2
        
        temp = "";
        minus = 0;
        for (int i = 0; i < max(s1.size(), s2.size()); i++) {
            int next_digit;
            if (i >= s2.size()) next_digit = (s1[i] - '0') - minus;
            else next_digit = s1[i] - s2[i] - minus;

            if (next_digit < 0) minus = 1;
            else minus = 0;
            next_digit = (next_digit + 10) % 10;

            temp += '0' + next_digit;
        }

        
        if (!minus) {

            num++;
            s1 = temp;
        }
    }

    ans += '0' + num;
    reverse(s1.begin(), s1.end());
    return s1;
}

int main() {

    string n, m;
    cin >> n >> m;

    string c;
    for (int i = 0; i < n.size(); i++) {
        c += n[i];
        c = divide(c, m);
    }
    ans = set_int(ans);
    c = set_int(c);

    cout << ans << '\n' << c << '\n';
}
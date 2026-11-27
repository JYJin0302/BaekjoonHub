#include <bits/stdc++.h>
using namespace std;

string addString(string s1, string s2) {

    if (s1.size() > s2.size()) swap(s1, s2);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    string ans;
    bool add1 = 0;
    for (int i = 0; i < s2.size(); i++) {
        int num;
        if (i < s1.size()) num = (s1[i] - '0') + (s2[i] - '0');
        else num = s2[i] - '0';
        num += add1;
        add1 = 0;
        if (num >= 10) add1 = 1;
        num %= 10;
        ans += num + '0';
    }
    if (add1) ans += '1';

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    string a, b;
    cin >> a >> b;

    cout << addString(a, b);
}
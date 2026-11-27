#include <bits/stdc++.h>
using namespace std;
int main() {
    int temp;
    string s;
    cin >> s;

    bool minus = false;
    int start = 0, end = 1;


    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != '+' && s[i] != '-' && i != s.size()-1) {
            end++;
        }
        else {
            stringstream ss(s.substr(start, end - start));
            ss >> temp;
            if (!minus) ans += temp;
            else ans -= temp;
            start = i + 1, end = i + 2;
            if (s[i] == '-') minus = true;
        }
    }

    cout << ans;

}
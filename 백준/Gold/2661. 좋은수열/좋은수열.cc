#include <bits/stdc++.h>
using namespace std;
string ans;
int n;
bool ok;

bool valid(string s) {
    int len = s.size();
    for (int i = 1; i <= s.size() / 2; i++) {
        string s1, s2;
        s1 = s.substr(len - i, i);
        s2 = s.substr(len - 2 * i, i);
        if (s1 == s2) return false;
    }

    return true;
}



void dfs(string s = "") {
    if (s.size() == n) {
        ans = s;
        ok = true;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        string temp = s + (char)('0' + i);
        if (valid(temp)) dfs(temp);
        if (ok) return;
    }
}



int main() {

    cin >> n;
    ok = false;
    ans = "";
    dfs();

    cout << ans;
}
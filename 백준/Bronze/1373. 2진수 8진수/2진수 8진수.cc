#include <bits/stdc++.h>
using namespace std;


int main() {

    string s;
    cin >> s;

    if (s == "0") {
        cout << 0;
        return 0;
    }

    vector<int> ans;
    int ix = s.size() - 1;
    while (ix >= 0) {

        int v = 0;
        v += s[ix] - '0';
        if (ix - 1 >= 0) v += 2 * (s[ix-1] - '0');
        if (ix - 2 >= 0) v += 4 * (s[ix-2] - '0');

        ans.push_back(v);
        ix -= 3;
    }

    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i;
}
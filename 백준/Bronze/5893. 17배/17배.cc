#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int n = s.size();

    reverse(s.begin(), s.end());
    vector<int> ans(n + 7);
    for (int i = 0; i < n; i++) {
        ans[i] += s[i] - '0';
        ans[i + 4] += s[i] - '0';
    }

    for (int i = 0; i < n + 6; i++) {
        if (ans[i] >= 2) ans[i + 1]++, ans[i] -= 2;
    }

    int idx = n + 6;
    while (ans[idx] == 0) idx--;

    for (int i = idx; i >= 0; i--) cout << ans[i];

}
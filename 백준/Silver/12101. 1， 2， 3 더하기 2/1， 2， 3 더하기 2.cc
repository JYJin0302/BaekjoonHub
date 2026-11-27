#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<string>> base(11);

    base[1] = { "1" };
    base[2] = { "1+1", "2" };
    base[3] = { "1+1+1", "1+2", "2+1", "3" };
    for (int i = 4; i <= n; i++) {
        for (string s : base[i - 3]) base[i].push_back(s + "+3");
        for (string s : base[i - 2]) base[i].push_back(s + "+2");
        for (string s : base[i - 1]) base[i].push_back(s + "+1");
    }

    sort(base[n].begin(), base[n].end());

    if (base[n].size() < k) cout << -1;
    else cout << base[n][k-1];
}
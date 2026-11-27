#include <bits/stdc++.h>
using namespace std;

int grid[1001][1001];

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) grid[i][j] = grid[i - 1][j - 1] + 1;
            else grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]);
            ans = max(grid[i][j], ans);
        }
    }

    cout << ans << '\n';

    vector<char> LCS;
    int ind1 = s1.size(), ind2 = s2.size();
    int cnt = ans;
    while (cnt) {
        if (grid[ind1 - 1][ind2] == cnt) ind1--;
        else if (grid[ind1][ind2 - 1] == cnt) ind2--;
        else {
            ind1--; ind2--;
            LCS.push_back(s1[ind1]);
            cnt--;
        }
    }

    for (int i = ans - 1; i >= 0; i--) {
        cout << LCS[i];
    }
}
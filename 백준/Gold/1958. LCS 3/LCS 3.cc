#include <bits/stdc++.h>
using namespace std;

int grid[101][101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int ans = 0;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            for (int k = 1; k <= s3.size(); k++) {
                if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1]) grid[i][j][k] = grid[i - 1][j - 1][k - 1] + 1;
                else grid[i][j][k] = max({ grid[i - 1][j][k], grid[i][j - 1][k], grid[i][j][k - 1] });

                ans = max(ans, grid[i][j][k]);
            }
        }
    }
    cout << ans;

}
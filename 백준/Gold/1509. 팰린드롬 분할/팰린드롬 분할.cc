#include <bits/stdc++.h>
using namespace std;

string s;
vector<vector<int>> pal;
vector<int> dp;
int search(int b) {
    if (b >= s.size()) return 0;
    if (dp[b] != -1) return dp[b];
   
    int temp = 10000;
    for (int i = b; i < s.size(); i++) {
        if (pal[b][i] == 1) {
            temp = min(temp, 1 + search(i + 1));
        }
    }
    return dp[b] = temp;
}


int main() {

    
    cin >> s;

    pal = vector<vector<int>> (s.size(), vector<int>(s.size()));

    for (int i = 0; i < s.size(); i++) {
        pal[i][i] = 1;
    }
    for (int i = 0; i < s.size() - 1; i++) {
        pal[i][i + 1] = (s[i] == s[i + 1]);
    }

    for (int i = 2; i < s.size(); i++) {
        for (int j = 0; j < s.size() - i; j++) {
            pal[j][j + i] = (pal[j + 1][j + i - 1] && s[j] == s[j + i]);
        }
    }
    dp = vector<int>(s.size(), -1);

    int ans = search(0);
    cout << ans;
}
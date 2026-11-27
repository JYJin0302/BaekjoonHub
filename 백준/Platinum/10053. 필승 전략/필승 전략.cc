#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dp[25][25];
vector<int> st[25];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
       
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        while (k--) {

            string s;
            cin >> s;

            int rs = 0;
            for (auto j : s) {
                rs |= (1 << (j - 'a'));
            }
            st[i].push_back(rs);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 100;
        }
    }

    for (int i = 0; i < n; i++) {

        int currSet = (1 << i);
        dp[i][i] = 0;

        int currVal = 1;
        while (1) {
            bool update = 0;
            int newSet = currSet;
            for (int j = 0; j < n; j++) {
                if ((currSet & (1 << j)) != 0) continue;
                for (auto k : st[j]) {
                    if ((k & currSet) == k) {
                        dp[j][i] = currVal;
                        newSet |= (1 << j);
                        break;
                    }
                }
            }
            if (newSet == currSet)  break;
            currVal++;
            currSet = newSet;
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == 100) dp[i][j] = -1;
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}
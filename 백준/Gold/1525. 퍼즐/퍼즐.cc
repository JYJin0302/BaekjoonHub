#include <bits/stdc++.h>
using namespace std;

int main() {

    map<string, bool> dp;

    string s = "";
    for (int i = 0; i < 9; i++) {
        char c;
        cin >> c;
        s += c;
    }

    string init = s;
    string ans = "123456780";

    int res = -1;
    queue<pair<int, string>> pq;
    pq.push({ 0, s });
    dp[init] = 1;
    while (!pq.empty()) {
        int k;
        tie(k, s) = pq.front();

        pq.pop();
        if (s == ans) {
            res = k;
            break;
        }

        int zero = find(s.begin(), s.end(), '0') - s.begin();

        if (zero % 3 > 0) {
            string temp = s;
            swap(temp[zero], temp[zero - 1]);
            if (!dp[temp]) {
                dp[temp] = 1;
                pq.push({ k + 1, temp });
            }
        }

        if (zero % 3 < 2) {
            string temp = s;
            swap(temp[zero], temp[zero + 1]);
            if (!dp[temp]) {
                dp[temp] = 1;
                pq.push({ k + 1, temp });
            }
        }

        if (zero >= 3) {
            string temp = s;
            swap(temp[zero], temp[zero - 3]);
            if (!dp[temp]) {
                dp[temp] = 1;
                pq.push({ k + 1, temp });
            }
        }
        if (zero < 6) {
            string temp = s;
            swap(temp[zero], temp[zero + 3]);
            if (!dp[temp]) {
                dp[temp] = 1;
                pq.push({ k + 1, temp });
            }
        }

    }
    cout << res;
}
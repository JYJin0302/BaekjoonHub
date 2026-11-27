#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

string dp[1010];

vector<char> tmp = { '(', ')', '{', '}', '[' ,']' };

string getMin(string a, string b) {

    if (a.size() < b.size()) {
        return a;
    }
    if (a.size() > b.size()) return b;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            int va = find(tmp.begin(), tmp.end(), a[i]) - tmp.begin();
            int vb = find(tmp.begin(), tmp.end(), b[i]) - tmp.begin();

            if (va < vb) return a;
            return b;
        }
    }
    return a;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    dp[1] = "()";
    dp[2] = "{}";
    dp[3] = "[]";

    for (int i = 4; i <= 1000; i++) {

        string tmp(i * 2, '}');
        for (int j = 1; j < i; j++) {
            tmp = getMin(tmp, dp[j] + dp[i - j]);
        }

        if (i % 2 == 0) {
            tmp = getMin(tmp, '(' + dp[i / 2] + ')');
        }
        if (i % 3 == 0) {
            tmp = getMin(tmp, '{' + dp[i / 3] + '}');
        }
        if (i % 5 == 0) {
            tmp = getMin(tmp, '[' + dp[i / 5] + ']');
        }

        dp[i] = tmp;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }

}

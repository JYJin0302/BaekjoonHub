#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int n = s.size();
    for (int i = n; i <= n * 2 - 1; i++) {

        bool ok = 1;
        int k = (i - 1) / 2;

        for (int j = 0; j <= k; j++) {
            int p1 = k - j, p2 = i - 1 - p1;
            if (p2 >= n) break;

            if (s[p1] != s[p2]) ok = 0;
        }

        if (ok) {
            cout << i;
            return 0;

        }
    }
}
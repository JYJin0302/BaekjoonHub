#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    sort(A.begin(), A.end());

    vector<int> B(1001);

    bool valid = 1;
    vector<string> ans(n);

    for (int i = 0; i < n; i++) {

        int a, b;
        tie(a, b) = A[i];

        if (B[0] != 0) valid = 0;
        string tmp;
        for (int j = 1; j <= a; j++) {
            if (B[j] > 1) valid = 0;
            tmp += char('0' + B[j]);
        }

        ans[b] = tmp;

        int ix = a;
        while (ix >= 0) {
            B[ix]++;
            if (B[ix] == 2) B[ix] = 0, ix--;
            else break;
        }
    }

    if (!valid) cout << -1;
    else {
        cout << 1 << '\n';
        for (string i : ans) cout << i << '\n';
    }

}
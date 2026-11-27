#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    int logn = log2(n);

    if (n <= pow(2, logn) + 1 || k < 4) {
        cout << -1;
        return 0;
    }
    
    cout << 2 * (n - 1) + 2 * logn << '\n';
    vector<int> ans = { 1 };

    int ix = 5;
    while (ix <= n) {
        ans.push_back(ix);

        int tx = log2(ix);
        if (ix == pow(2, tx) + 1) {
            ans.push_back(ix - 1);
        }
        ix+= 2;
    }

    if (ix == n + 2) ix = n - 1;
    else ix = n;

    while (ix >= 2) {
        ans.push_back(ix);

        int tx = log2(ix);
        if (ix == pow(2, tx) + 2) {
            ix -= 2;
        }
        ix -= 2;
    }

    ans.push_back(3);
    ans.push_back(1);

    for (auto i : ans) cout << i << ' ';

}
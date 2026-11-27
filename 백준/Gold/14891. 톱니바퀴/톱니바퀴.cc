#include <bits/stdc++.h>
using ll = long long;
using namespace std;

string s[4];
int idx[4] = { 0, 0, 0, 0 };

int r_idx(int x) {
    return (idx[x] + 2) % 8;
}
int l_idx(int x) {
    return (idx[x] + 6) % 8;
}

void f(int ix, int dir) {

    vector<int> diff(4);
    diff[ix] = -dir;
    for (int i = ix; i < 3; i++) {
        if (s[i][r_idx(i)] != s[i + 1][l_idx(i + 1)]) diff[i + 1] = -diff[i];
    }
    for (int i = ix; i > 0; i--) {
        if (s[i][l_idx(i)] != s[i - 1][r_idx(i - 1)]) diff[i - 1] = -diff[i];
    }
    

    for (int i = 0; i < 4; i++) idx[i] = (idx[i] + diff[i] + 8) % 8;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    for (int i = 0; i < 4; i++) cin >> s[i];

    int q;
    cin >> q;
    while (q--) {

        int ix, dir;
        cin >> ix >> dir;

        f(ix-1, dir);
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans += pow(2, i) * (int)(s[i][idx[i]] - '0');
    }
    cout << ans;
}
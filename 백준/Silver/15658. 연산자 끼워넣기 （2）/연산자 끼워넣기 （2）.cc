#include <bits/stdc++.h>
using namespace std;


int n, maxn, minn;
vector<int> item;
vector<int> base;

void solve(int ans, int cnt) {
    if (cnt == n - 1) {
        maxn = max(maxn, ans);
        minn = min(minn, ans);
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!item[i]) continue;
        item[i]--;
        switch (i) {
        case 0:
            solve(ans + base[cnt + 1], cnt + 1);
            break;
        case 1:
            solve(ans - base[cnt + 1], cnt + 1);
            break;
        case 2:
            solve(ans * base[cnt + 1], cnt + 1);
            break;
        case 3:
            solve(ans / base[cnt + 1], cnt + 1);
            break;
        }
        item[i]++;
    }
}

int main() {
    cin >> n;

    base = vector<int>(n);
    for (auto& i : base) cin >> i;

    item = vector<int>(4);
    for (auto& i : item) cin >> i;

    maxn = -1e9;
    minn = 1e9;

    solve(base[0], 0);
    cout << maxn << '\n' << minn;
}
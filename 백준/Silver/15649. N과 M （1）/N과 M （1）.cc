#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> used;
vector<int> ans;
void solve(int n, int cnt) {
    if (cnt == m) {
        for (int i : ans) cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        used[i] = 1;
        ans[cnt] = i;
        solve(n, cnt + 1);
        used[i] = 0;
    }
}


int main() {
    cin >> n >> m;
    used = vector<int>(n + 1);
    ans = vector<int>(m);

    solve(n, 0);

}
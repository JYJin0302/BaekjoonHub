#include <bits/stdc++.h>
using namespace std;



int n, m;
vector<int> ans;
void solve(int n, int cnt, int maxnum) {
    if (cnt == m) {
        if (ans.back() == maxnum) {
            for (int i : ans) cout << i << ' ';
            cout << '\n';
        }
        return;
    }


    for (int i = 1; i <= n; i++) {
        if (i <= maxnum) continue;
        ans[cnt] = i;
        solve(n, cnt + 1, i);
    }
}


int main() {
    cin >> n >> m;
    ans = vector<int>(m);

    solve(n, 0, 0);

}
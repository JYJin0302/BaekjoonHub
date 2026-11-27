#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans;
void solve(int n, int cnt) {
    if (cnt == m) {
        for (int i : ans) cout << i << ' ';
        cout << '\n';
        return;
    }


    for (int i = 1; i <= n; i++) {
        
        ans[cnt] = i;
        solve(n, cnt + 1);
    }
}


int main() {
    cin >> n >> m;
    ans = vector<int>(m);

    solve(n, 0);

}
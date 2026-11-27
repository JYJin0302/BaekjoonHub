#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans;
vector<int>base;
vector<bool> check;

void p(int cnt) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        ans[cnt] = base[i];
        check[i] = true;
        p(cnt + 1);
        check[i] = false;
    }

}



int main() {


    cin >> n >> m;
    ans = vector<int>(m);
    check = vector<bool>(n);
    base = vector<int>(n);
    for (auto& i : base)cin >> i;
    sort(base.begin(), base.end());

    p(0);

}
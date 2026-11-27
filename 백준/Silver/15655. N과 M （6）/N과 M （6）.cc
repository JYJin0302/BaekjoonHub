#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans;
vector<int>base;
vector<bool> check;

void p(int f = 0, int cnt = 0) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = f; i < n; i++) {
        if (check[i]) continue;
        ans[cnt] = base[i];
        check[i] = true;
        p(i+1, cnt + 1);
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

    p();

}
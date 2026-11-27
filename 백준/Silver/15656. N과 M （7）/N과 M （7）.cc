#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ans;
vector<int>base;
vector<bool> check;

void p(int cnt = 0) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        ans[cnt] = base[i];
        p(cnt + 1);
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
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> base;
vector<int> used;
vector<int> ans(6);

void dps(int maxi, int cnt) {
    if (cnt == 6) { 
        for (int i : ans) cout << i << ' ';
        cout << '\n';
        return; }
    for (int i = 0; i < n; i++) {
        if (used[i] || i < maxi) continue;
        used[i] = 1;
        ans[cnt] = base[i];
        dps(i, cnt + 1);
        used[i] = 0;
    }
}


int main() {
    cin >> n;
    while (n) {
        base = vector<int>(n);
        used = vector<int>(n);
        for (auto& i : base) cin >> i;

        dps(0, 0);
        cout << '\n';
        cin >> n;
    }

}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m, l;
    cin >> n >> m >> l;

    vector<pair<int, int>> A;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (b > l) continue;

        A.push_back(mp(a - (l - b), 1));
        A.push_back(mp(a + (l - b) + 1, -1));
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        A.push_back(mp(x, 10 + i));
    }

    sort(A.begin(), A.end());

    vector<int> ans(m);
    int cnt = 0;
    for (auto f : A) {
        if (abs(f.second) == 1) cnt += f.second;
        else {
            ans[f.second - 10] = cnt;
        }
    }

    for (auto f : ans) cout << f << '\n';

}
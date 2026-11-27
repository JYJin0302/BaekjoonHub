#include <bits/stdc++.h>
using namespace std;
#define INF 1000000007

vector<int> from, value, maxv;
vector<vector<pair<int, int>>> rev;

void solve(int x) {

    if (maxv[x] != -INF) return;

    for (auto i : rev[x]) {
        int a, b;
        tie(a, b) = i;
        solve(a);
        if (maxv[a] +value[x]- b > maxv[x]) {
            maxv[x] = maxv[a] +value[x] - b;
            from[x] = a;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {

        int n, e;
        cin >> n >> e;

        value = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) cin >> value[i];
        from = vector<int>(n + 1);
        rev = vector<vector<pair<int, int>>>(n + 1);

        for (int i = 0; i < e; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            rev[b].push_back({ a, c });
        }
        maxv = vector<int>(n + 1, -INF);
        maxv[1] = value[1];

        for (int i = 2; i <= n; i++) {
            solve(i);
        }

        int ans = max_element(maxv.begin(), maxv.end()) - maxv.begin();
        int ind = ans;
        vector<int> path;
        while (ind) {
            path.push_back(ind);
            ind = from[ind];
        }

        cout << maxv[ans] << ' ' << path.size() << '\n';
        reverse(path.begin(), path.end());
        for (int i : path) cout << i << ' ';
        cout << '\n';
    }
}
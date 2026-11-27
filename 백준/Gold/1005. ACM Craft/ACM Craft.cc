#include <bits/stdc++.h>
using namespace std;


int t, n, k, x, y, w;
vector<vector<int>> rule;
vector<int> buildtime;

vector<int> path;


void dfs(int i) {

    if (rule[i].empty()) {
        path[i] = buildtime[i]; return;
    }
    int temp = -1;
    for (int k : rule[i]) {
        if (path[k] == -1) dfs(k);
        temp = max(temp, path[k] + buildtime[i]);
    }
    path[i] = temp;
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        buildtime = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> buildtime[i];
        }

        rule = vector<vector<int>>(n + 1);
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            rule[y].push_back(x);
        }
        path = vector<int>(n + 1, -1);
        cin >> w;

        dfs(w);


        cout << *max_element(path.begin(), path.end()) << '\n';
    }
}
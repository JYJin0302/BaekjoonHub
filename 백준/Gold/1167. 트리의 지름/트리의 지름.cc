#include <bits/stdc++.h>
using namespace std;


vector<vector<pair<int, int>>> base;
vector<int> path;


int v, n, t1, t2, a, b;
void dfs(int i, int p = 0) {
    for (auto k : base[i]) {
        tie(a, b) = k;
        if (a == p) continue;
        if (path[a] < path[i] + b) {
            path[a] = path[i] + b;
            dfs(a, i);
        }
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> v;
    path = vector<int>(v + 1);
    base = vector<vector<pair<int, int >>>(v + 1);
    for (int i = 0; i < v; i++) {
        cin >> n >> t1;
        while (t1 != -1) {
            cin >> t2;
            base[n].push_back({ t1, t2 });
            cin >> t1;
        }
    }

    dfs(1);
    int x = max_element(path.begin(), path.end()) - path.begin();
    path = vector<int>(v + 1);
    dfs(x);
    cout << *max_element(path.begin(), path.end());

}
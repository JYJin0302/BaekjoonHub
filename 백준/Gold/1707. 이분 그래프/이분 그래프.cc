#include <bits/stdc++.h>
using namespace std;


vector<vector<int>> base;
vector<bool> color;
vector<bool> check;
bool ok;

void dfs(int v) {

    for (auto i : base[v]) {
        if (check[i]) {
            if (color[i] == color[v]) {
                ok = false;
                return;
            }
            continue;
        }
        check[i] = true;
        color[i] = color[v] ^ 1;
        dfs(i);
    }

}

int main() {
    int t, v, e, n1, n2;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        base = vector<vector<int>>(v + 1);
        color = vector<bool>(v + 1);
        check = vector<bool>(v + 1);
        for (int i = 0; i < e; i++) {
            cin >> n1 >> n2;
            base[n1].push_back(n2);
            base[n2].push_back(n1);
        }
        ok = true;
        int test = 1;
        while (ok && test <= v) {
            if (!check[test]) {
                color[test] = 0;
                check[test] = true;
                dfs(test);
            }
            test++;
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }


}
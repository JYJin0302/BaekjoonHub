#include <bits/stdc++.h>
using namespace std;

vector<int> root;
int find(int n) {

    if (n == root[n]) return n;

    return root[n] = find(root[n]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, a, b, c;
    cin >> v >> e;

    vector<tuple<int, int, int>> edge;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        edge.push_back({ c, a, b });
    }
    sort(edge.begin(), edge.end());

    root = vector<int>(v + 1);
    for (int i = 1; i <= v; i++) {
        root[i] = i;
    }
    vector<int> ans;

    for (int i = 0; i < e; i++) {
        tie(a, b, c) = edge[i];
        if (find(b) == find(c)) continue;
        root[find(b)] = root[c];
        ans.push_back(a);
    }
    int res = 0;
    for (int i : ans) res += i;
    res -= *max_element(ans.begin(), ans.end());
    
    cout << res;    
}
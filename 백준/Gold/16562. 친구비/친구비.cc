#include <bits/stdc++.h>
using namespace std;

vector<int> root;

int find(int n) {
    if (root[n] == n) return n;

    return root[n] = find(root[n]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k, a, b;
    cin >> n >> m >> k;

    root = vector<int>(n+1);
    for (int i = 1; i <= n; i++) root[i] = i;

    vector<int> cost(n);
    for (auto& i : cost) cin >> i;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        root[find(a)] = find(b);
    }
    vector<int> roots;
    for (int i = 1; i <= n; i++) {
        if (root[i] == i) roots.push_back(i);
    }

    int ans = 0;
    for (int k : roots) {
        int temp = 100000;
        for (int i = 1; i <= n; i++) {
            if (find(i) == k) temp = min(temp, cost[i-1]);
        }
        ans += temp;
    }

    if (ans <= k) cout << ans;
    else cout << "Oh no";
}
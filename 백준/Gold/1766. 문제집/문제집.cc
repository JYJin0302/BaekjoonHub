#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;

    vector<int> Degree(n + 1);

    vector<vector<int>> rule(32001);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        rule[a].push_back(b);
        Degree[b]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (Degree[i] == 0) pq.push(-i);
    }

    while (!pq.empty()) {
        a = pq.top();
        a *= -1;
        cout << a << ' ';
        pq.pop();
        for (int i : rule[a]) {
            Degree[i]--;
            if (Degree[i] == 0) pq.push(-i);
        }
    }

}
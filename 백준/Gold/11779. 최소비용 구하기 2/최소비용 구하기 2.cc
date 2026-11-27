#include <bits/stdc++.h>
using namespace std;
#define INF 1000000001

int n, m, a, b, c;
vector<vector<pair<int, int>>> base;
vector<int> path(n + 1);
vector<int> from(n + 1);
priority_queue<pair<int, int>> pq;
vector<bool> check;

void dijk() {
    while (!pq.empty()) {
        tie(a, b) = pq.top();
        pq.pop();
        if (check[b]) continue;
        check[b] = 1;
        for (auto i : base[b]) {
            tie(a, c) = i;
            if (!check[a] && path[a] > path[b] + c) {
                path[a] = path[b] + c;
                from[a] = b;
                pq.push({ -path[a], a });
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    base = vector<vector<pair<int, int>>>(n + 1);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        base[a].push_back({ b, c });
    }

    path = vector<int>(n + 1, INF);
    from = vector<int>(n + 1);
    check = vector<bool>(n + 1);

    int s, t;
    cin >> s >> t;

    pq.push({ 0, s });
    path[s] = 0;
    dijk();

    vector<int> A = { t };
    int temp = t;
    while (temp != s) {
        A.push_back(from[temp]);
        temp = from[temp];
    }

    cout << path[t] << '\n';
    cout << A.size() << '\n';
    for (auto it = A.rbegin(); it != A.rend(); it++) {
        cout << *it << ' ';
    }
    cout << '\n';
}
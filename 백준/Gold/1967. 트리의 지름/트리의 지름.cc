#include <bits/stdc++.h>
using namespace std;

int n, n1, n2, n3;
vector<int> path;
priority_queue<pair<int, int>> pq;
vector<vector<pair<int, int>>> base;
vector<bool>  check;

void dijk() {
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if (check[v]) continue;
        check[v] = true;
        for (auto u : base[v]) {
            n1 = u.first;
            int w = u.second;
            if (check[n1]) continue;
            if (path[n1] < path[v] + w) {
                path[n1] = path[v] + w;
                pq.push({ path[n1], n1 });
            }
        }
    }
}

int main() {

    cin >> n;
    check = vector<bool>(n + 1);
    path = vector<int>(n + 1, -1);

    base = vector<vector<pair<int, int>>>(n + 1);
    for (int i = 0; i < n-1; i++) {
        cin >> n1 >> n2 >> n3;
        base[n1].push_back({ n2, n3 });
        base[n2].push_back({ n1, n3 });
    }
    path[1] = 0;
    pq.push({ 0, 1 });
    dijk();

    int start = max_element(path.begin(), path.end()) - path.begin();

    check = vector<bool>(n + 1);
    path = vector<int>(n + 1, -1);
    path[start] = 0;
    pq.push({ 0, start });
    dijk();

    cout << *max_element(path.begin(), path.end());

}
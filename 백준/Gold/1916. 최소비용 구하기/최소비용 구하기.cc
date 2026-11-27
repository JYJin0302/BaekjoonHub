#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647;

int v, e, start, target, n1, n2, w, a, b;
vector<int> ans;
vector<bool> check;
priority_queue<pair<int, int>> pq;


int main() {
    cin >> v >> e;
    ans = vector<int>(v + 1);
    check = vector<bool>(v + 1);

    vector<vector<pair<int, int>>> base(v + 1);
    for (int i = 0; i < e; i++) {
        cin >> n1 >> n2 >> w;
        base[n1].push_back({ n2, w });
    }
    cin >> start >> target;

    for (int i = 1; i <= v; i++) {
        ans[i] = INF;
    }
    ans[start] = 0;

    pq.push({ 0, start });
    while (!pq.empty()) {
        int g = pq.top().second; pq.pop();
        if (check[g]) continue;
        check[g] = true;
        for (auto i : base[g]) {

            a = i.first; b = i.second;
            if (ans[a] > ans[g] + b) {
                ans[a] = ans[g] + b;
                pq.push({ -ans[a], a });
            }
        }
    }

    cout << ans[target];

}
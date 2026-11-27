#include <bits/stdc++.h>
using namespace std;


int v, e, st, n1, n2, w, a, b;
vector<int> ans;
vector<bool> check;
priority_queue<pair<int, int>> pq;



int main() {
    cin >> v >> e >> st;
    ans = vector<int>(v+1);
    check = vector<bool>(v + 1);

    vector<vector<pair<int, int>>> base(v + 1);
    for (int i = 0; i < e; i++) {
        cin >> n1 >> n2 >> w;
        base[n1].push_back({ n2, w });
    }

    pq.push({ 0, st });
    while (!pq.empty()) {
        int g = pq.top().second; pq.pop();
        if (check[g]) continue;
        check[g] = true;
        for (auto i : base[g]) {
            
            a = i.first; b = i.second;
            if (a == st) continue;
            if (ans[a] == 0 || ans[a] > ans[g] + b) {
                ans[a] = ans[g] + b;
                pq.push({ -ans[a], a });
            }
        }
    }

    for (int i = 1; i <= v; i++) {
        if (i == st) cout << 0;
        else if (ans[i] == 0) cout << "INF";
        else cout << ans[i];
        cout << '\n';
    }

}
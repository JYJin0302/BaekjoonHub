#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

vector<pair<int, int>> adj[101010];
int dist[101010];
int root[101010];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

vector<int> num;
int getIdx(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k, q;
    cin >> n >> m >> k >> q;

    memset(dist, -1, sizeof(dist));

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    priority_queue<pair<int, int>> pq;
    while (k--) {
        int x;
        cin >> x;

        pq.push({ 0, x });
    }
    while (!pq.empty()) {
        int a, b;
        tie(a, b) = pq.top();
        pq.pop();

        if (dist[b] != -1) continue;
        dist[b] = -a;

        for (auto i : adj[b]){
            if (dist[i.first] == -1) {
                pq.push(mp(a - i.second, i.first));
            }
        }
    }
    vector<pair<int, pair<int, int>>> edge;
    for (int i = 1; i <= n; i++) {
        for (auto& f : adj[i]) {
            if (f.first > i) {
                edge.push_back(mp(min(dist[i], dist[f.first]), mp(i, f.first)));
                num.push_back(min(dist[i], dist[f.first]));
            }
        }
    }
    sort(edge.rbegin(), edge.rend());

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    int sn = num.size();

    vector<pair<int, int>> md(q, mp(0, sn-1));
    vector<pair<int, int>> query;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        query.push_back(mp(a, b));
    }


    vector<int> ans(q);
    while (1) {
        bool ck = 0;
        vector<vector<int>> qList(sn);

        for (int i = 0; i < q; i++) {
            if (md[i].first <= md[i].second) {
                qList[(md[i].first + md[i].second) / 2].push_back(i);
                ck = 1;
            }
        }

        if (!ck) break;

        for (int i = 1; i <= n; i++) root[i] = i;

        int ix = 0;
        while (ix < edge.size()) {

            int curr = edge[ix].first;
            while (ix < edge.size() && edge[ix].first == curr) {

                int u = edge[ix].second.first;
                int v = edge[ix].second.second;

                u = find(u), v = find(v);
                if (u != v) root[u] = v;

                ix++;
            }

            int currix = getIdx(curr);
            for (auto idx : qList[currix]) {

                int u = query[idx].first;
                int v = query[idx].second;

                if (find(u) == find(v)) {
                    ans[idx] = curr;
                    md[idx].first = currix + 1;
                }
                else {
                    md[idx].second = currix - 1;
                }
            }
        }
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}
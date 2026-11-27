#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[500001];
bool visited[500001];
string s;

void solve() {

    queue<int> q;
    q.push(0);
    visited[0] = 1;
    cout << s[0];

    while (1) {

        vector<pair<int, int>> res;
        while (!q.empty()) {

            int v = q.front();
            q.pop();
            
            for (auto i : adj[v]) if (!visited[i]) {
                visited[i] = 1;
                res.push_back({ s[i] - 'a', i });
            }
        }
        if (res.empty()) break;

        sort(res.rbegin(), res.rend());

        int mv = res[0].first;
        cout << char(mv + 'a');

        for (auto i : res) if (i.first == mv) {
            q.push(i.second);
        }
        res.clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    
    cin >> s;

    for (int i = 0; i < n-1; i++) {

        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);

    }
    solve();
}
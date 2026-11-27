#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<int>A(n);
        for (auto& i : A) cin >> i;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                adj[A[i]].push_back(A[j]);
            }
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            
            auto tt = find(adj[a].begin(), adj[a].end(), b);
            if (tt != adj[a].end()) {
                adj[a].erase(tt);
                adj[b].push_back(a);
            }
            else {
                tt = find(adj[b].begin(), adj[b].end(), a);
                adj[b].erase(tt);
                adj[a].push_back(b);
            }
        }

        vector<int> topo(n + 1);
        for (int i = 1; i <= n; i++) {
            
            for (int k : adj[i]) topo[k]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (topo[i] == 0) q.push(i);
        }

        vector<int> ans;
        bool question = false;
        bool impossible = false;
        while (ans.size() < n) {
            if (q.size() > 1) {
                question = true;
                break;
            }

            if (q.size() == 0) {
                impossible = true;
                break;
            }

            int k = q.front();
            q.pop();
            ans.push_back(k);

            for (int i : adj[k]) {
                topo[i]--;
                if (topo[i] == 0) q.push(i);
            }
        }

        if (question) {
            cout << "?\n";
        }
        else if (impossible) {
            cout << "IMPOSSIBLE\n";
        }
        else {
            for (int i : ans) cout << i << ' ';
            cout << '\n';
        }
    }
}
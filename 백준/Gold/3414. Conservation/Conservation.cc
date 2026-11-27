#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[101010];

void solve() {

    int n, m;
    cin >> n >> m;

    vector<int> A(n+1), topo(n+1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) adj[i].clear();

    vector<pair<int, int>> edge;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edge.push_back({ a, b });
        adj[a].push_back(b);
    }

    int ans = n + 10;


    for (auto &[a, b] : edge) {
        topo[b]++;
    }

    queue<int> q1, q2;
    for (int i = 1; i <= n; i++) {
        if (topo[i] == 0) {
            if (A[i] == 1) q1.push(i);
            else q2.push(i);

        }
    }
    // try 1 first

    int tans = 0, curr = 1;
    while (!q1.empty() || !q2.empty()) {
        int a;
        if (curr == 1) {
            if (q1.empty()) {
                curr ^= 1;
                tans++;
                continue;
            }
            a = q1.front();
            q1.pop();
        }
        else{
            if (q2.empty()) {
                curr ^= 1;
                tans++;
                continue;
            }
            a = q2.front();
            q2.pop();
        }

        for (auto i : adj[a]) {
            topo[i]--;
            if (topo[i] == 0) {
                if (A[i] == 1) q1.push(i);
                else q2.push(i);
            }
        }
    }
    ans = min(ans, tans);

    for (auto& [a, b] : edge) {
        topo[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (topo[i] == 0) {
            if (A[i] == 1) q1.push(i);
            else q2.push(i);

        }
    }

    tans = 0, curr = 0;
    while (!q1.empty() || !q2.empty()) {
        int a;
        if (curr == 1) {
            if (q1.empty()) {
                curr ^= 1;
                tans++;
                continue;
            }
            a = q1.front();
            q1.pop();
        }
        else {
            if (q2.empty()) {
                curr ^= 1;
                tans++;
                continue;
            }
            a = q2.front();
            q2.pop();
        }

        for (auto i : adj[a]) {
            topo[i]--;
            if (topo[i] == 0) {
                if (A[i] == 1) q1.push(i);
                else q2.push(i);
            }
        }
    }
    ans = min(ans, tans);

    cout << ans << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
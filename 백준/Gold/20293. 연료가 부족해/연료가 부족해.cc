#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int R, C;
    cin >> R >> C;

    int n;
    cin >> n;

    vector<tuple<int, int, int>> A(n);
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        A[i] = { a, b, c };
    }

    vector<vector<int>> adj(n);
    vector<int> need(n, -1), topo(n);

    for (int i = 0; i < n; i++) {
        int x, y, z;
        tie(x, y, z) = A[i];
        for (int j = i + 1; j < n; j++) {
            int a, b, c;
            tie(a, b, c) = A[j];

            
            if (a >= x && b >= y) {
                adj[j].push_back(i);
                topo[i]++;
            }
            else if (x >= a && y >= b) {
                adj[i].push_back(j);
                topo[j]++;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (topo[i] == 0) {
            q.push(i);
            int a, b, c;
            tie(a, b, c) = A[i];

            need[i] = max(0, R - a + C - b - c);
        }
    }

    while (!q.empty()) {
        int i = q.front();
        q.pop();
        int a, b, c;
        tie(a, b, c) = A[i];

        for (int j : adj[i]) {

            int x, y, z;
            tie(x, y, z) = A[j];

            if (need[j] == -1) {
                need[j] = max(0, a - x + b - y - z + need[i]);
            }
            else need[j] = min(need[j], max(0, a - x + b - y - z + need[i]));

            topo[j]--;
            if (topo[j] == 0) q.push(j);
        }
    }


    int ans = R + C - 2;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        tie(a, b, c) = A[i];
        ans = min(ans, a + b - 2 + need[i]);
    }

    cout << ans;
}
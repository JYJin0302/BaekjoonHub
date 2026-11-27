#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[1001], rev[1001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        adj[i].push_back(a);
        adj[i].push_back(b);
        rev[a].push_back(i);
        rev[b].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        int a = adj[i][0], b = adj[i][1];

        queue<int> q;
        vector<bool> tmp1(n + 1), tmp2(n + 1), tmp(n+1);
        q.push(a);
        tmp1[a] = 1;
        while (!q.empty()) {

            int x = q.front();
            q.pop();

            for (auto k : rev[x]) {
                if (!tmp1[k] && k != i) {
                    tmp1[k] = 1;
                    q.push(k);
                }
            }

        }

        swap(tmp1, tmp2);
        swap(a, b);
        q.push(a);
        tmp1[a] = 1;
        while (!q.empty()) {

            int x = q.front();
            q.pop();

            for (auto k : rev[x]) {
                if (!tmp1[k] && k != i) {
                    tmp1[k] = 1;
                    q.push(k);
                }
            }
        }

        q.push(i);
        tmp[i] = 1;
        while (!q.empty()) {
            int x = q.front();
            q.pop();

            for (auto k : rev[x]) {
                if (!tmp[k]) {
                    tmp[k] = 1;
                    q.push(k);
                }
            }
        }

        bool ok = 1;
        for (int j = 1; j <= n; j++) {
            if (tmp1[j] && tmp2[j] && tmp[j]) ok = 0;
        }

        if (ok) cout << 'N';
        else cout << 'Y';
    }

}
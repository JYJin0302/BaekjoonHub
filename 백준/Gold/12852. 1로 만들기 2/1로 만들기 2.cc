#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> path(n + 1, 100001);
    path[n] = 0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int a = q.front();
        q.pop();
        if (a == 1) break;

        if (a % 2 == 0) {
            if (path[a / 2] > path[a] + 1) {
                path[a / 2] = path[a] + 1;
                q.push(a / 2);
            }
        }

        if (a % 3 == 0) {
            if (path[a / 3] > path[a] + 1) {
                path[a / 3] = path[a] + 1;
                q.push(a / 3);
            }
        }

        if (path[a - 1] > path[a] + 1) {
            path[a - 1] = path[a] + 1;
            q.push(a - 1);
        }

    }

    cout << path[1] << '\n';
    vector<int> ans;
    int c = 1;
    while (c <= n) {
        ans.push_back(c);
        int nc = 0;
        if (c == n)break;
        if (c+ 1 <= n && path[c + 1] == path[c] - 1) nc = c + 1;
        if (c*2 <= n && path[c * 2] == path[c] - 1) nc = c * 2;
        if (c*3 <= n && path[c * 3] == path[c] - 1) nc = c * 3;
        c = nc;
    }

    for (auto it = ans.rbegin(); it != ans.rend(); it++) {
        cout << *it << ' ';
    }
}
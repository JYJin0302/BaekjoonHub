#include <bits/stdc++.h>
using namespace std;
#define INF 10000000

int main() {
    int n, k, a, b;
    cin >> n >> k;

    vector<pair<int, int>> path(max(k, n) + 2, { INF, 1 });
    path[n] = { 0, 1 };
    queue<int> q;
    q.push(n);
    while (!q.empty()) {

        a = q.front();
        q.pop();
                
        if (a == k) {
            cout << path[a].first << '\n' << path[a].second << '\n';
            return 0;
        }

        if (a!= 0 && a * 2 <= max(n, k) + 1) {
            if (path[2*a].first > path[a].first + 1) {
                path[2*a] = { path[a].first + 1, path[a].second };
                q.push(2*a);
            }
            else if (path[2*a].first < path[a].first + 1) ;
            else {
                path[2*a].second += path[a].second;
            }
        }

        if (a > 0) {
            if (path[a - 1].first > path[a].first + 1) {
                path[a - 1] = { path[a].first + 1, path[a].second };
                q.push(a-1);
            }
            else if (path[a - 1].first < path[a].first + 1) ;
            else {
                path[a - 1].second += path[a].second;
            }
        }
        if (a <= max(k, n)) {
            if (path[a + 1].first > path[a].first + 1) {
                path[a + 1] = { path[a].first + 1, path[a].second };
                q.push(a + 1);
            }
            else if (path[a + 1].first < path[a].first + 1) ;
            else {
                path[a + 1].second += path[a].second;
            }
        }
    }
}
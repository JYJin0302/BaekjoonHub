#include <bits/stdc++.h>
using namespace std;
#define INF 10000000

int main() {
    int n, k, a, b;
    cin >> n >> k;

    vector<int> path(max(k, n) + 2, INF);
    vector<bool> check(max(k, n) + 2);

    priority_queue<pair<int, int>> pq;  // cnt, position
    pq.push({ 0, k});
    while (!pq.empty()) {
        
        tie(a, b) = pq.top();
        pq.pop();

        if (check[b]) continue;
        path[b] = a*-1;
        check[b] = 1;

        if (b == n) {
            cout << a * -1;
            return 0;
        }

        if (b % 2 == 0 && !check[b/2]) {
            pq.push({ a, b / 2 });
        }
        if (b <= max(k, n) && !check[b+1]) {
            pq.push({ a - 1, b + 1 });
        }
        if (b > 0 && !check[b-1]) {
            pq.push({ a - 1, b - 1 });
        }
    }
}
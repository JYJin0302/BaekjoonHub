#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b, c;
    cin >> n;

    priority_queue<pair<int ,int>> pq;
    while (n--) {
        cin >> a;
        if (a == 0) {
            if (pq.empty()) cout << "0\n";
            else {
                tie(b, c) = pq.top();
                if (c == 1) cout << b << '\n';
                else cout << -b << '\n';
                pq.pop();
            }
        }
        else {
            if (a > 0) pq.push({-a, 0});
            else pq.push({a, 1});
        }
    }

}
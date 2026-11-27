#include <bits/stdc++.h>
using namespace std;

priority_queue<int> pq;

int main() {
    int n, t, a, b;
    cin >> n;
    while (n--) {
        cin >> t;
        pq.push(-t);
    }

    int ans = 0;
    while (pq.size() > 1) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans -= a + b;
    }
    cout << ans;
}
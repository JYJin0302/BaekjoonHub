#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
    int n;
    cin >> n;

    vector<vector<int>> assign(1001);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        assign[a].push_back(b);
    }

    int ans = 0;
    priority_queue<int> pq;
    for (int day = 1000; day > 0; day--) {

        for (int i : assign[day]) pq.push(i);

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
}
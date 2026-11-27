#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int ans = 1;
    int l = 0;
    deque<pair<int, int>> maxQ, minQ;
    maxQ.push_back({ A[0], 0 });
    minQ.push_back({ A[0], 0 });

    for (int i = 1; i < n; i++) {

        ll num = A[i];
        while (!maxQ.empty() && (maxQ.back().first <= num || maxQ.back().second < l)) {
            maxQ.pop_back();
        }
        maxQ.push_back({ num, i });

        while (!minQ.empty() && (minQ.back().first >= num || minQ.back().second < l)) {
            minQ.pop_back();
        }
        minQ.push_back({ num, i });
        while (maxQ.front().first - minQ.front().first > t) {
            l = min(maxQ.front().second, minQ.front().second) + 1;
            while (maxQ.front().second < l) maxQ.pop_front();
            while (minQ.front().second < l) minQ.pop_front();
        }

        ans = max(ans, i - l + 1);

    }
    cout << ans;
}
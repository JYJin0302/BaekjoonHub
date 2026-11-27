#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<int> A(m);
    for (auto& i : A) cin >> i;
    deque<int> dq;
    for (int i = 1; i <= n; i++) dq.push_back(i);

    int curr = 0, ans = 0;
    while (curr < m) {
        int cnt = 0;
        while (A[curr] != dq.front()) {
            dq.push_back(dq.front());
            dq.pop_front();
            cnt++;
        }
        ans += min(cnt, (int)dq.size() - cnt);
        dq.pop_front();
        curr++;
    }
    cout << ans;

}
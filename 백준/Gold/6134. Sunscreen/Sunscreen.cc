#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> A(n), B(m);
    for (auto& [a, b] : A) cin >> a >> b;
    for (auto& [a, b] : B) cin >> a >> b;

    sort(all(A));
    sort(all(B));

    int ia = 0, ib = 0;

    int ans = 0;
    priority_queue<int> pq;
    while (ib < m) {
        while (ia < n && A[ia].x <= B[ib].x) {
            pq.push(-A[ia].y);
            ia++;
        }
        while (!pq.empty() && -pq.top() < B[ib].x) pq.pop();

        while (B[ib].y && !pq.empty()) {
            B[ib].y--;
            pq.pop();
            ans++;
        }
        ib++;
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //  cin >> t;
    while (t--) solve();
}
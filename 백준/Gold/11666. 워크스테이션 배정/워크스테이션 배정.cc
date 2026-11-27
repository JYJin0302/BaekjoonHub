#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {

        int a, b;
        cin >> a >> b;

        A.push_back(mp(a, b));
    }

    sort(A.begin(), A.end());

    priority_queue<int> pq;

    int ans = 0;
    for (int i = 0; i < n; i++) {

        while (!pq.empty() && -pq.top() + m < A[i].first) pq.pop();

        if (!pq.empty() && -pq.top() <= A[i].first) pq.pop(), ans++;

        pq.push(-A[i].first - A[i].second);
    }

    cout << ans;

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
}
#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };



void solve() {

    int n;
    cin >> n;
    vector<int> inp(n - 2);
    for (auto& i : inp) cin >> i;

    vector<int> topo(n + 1);
    for (int i : inp) {
        topo[i]++;
    }

    priority_queue<int> pq;
    for (int i = 1; i <= n; i++) {
        if (topo[i] == 0) pq.push(i);
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 2; i++) {
        int x = pq.top(), y = inp[i];
        pq.pop();

        ans.pb({ min(x, y), max(x, y) });
        topo[y]--;
        if (topo[y] == 0) pq.push(y);
    }
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    ans.push_back({ min(a, b), max(a, b) });

    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i.first << ' ' << i.second << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;

    while (T--) {
        solve();
    }
}
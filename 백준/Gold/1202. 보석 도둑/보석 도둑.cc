#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m, v, a, b;
    cin >> n >> k;

    vector<vector<int>> jewel(1000001);

    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        jewel[m].push_back(v);
    }

    vector<int> bag(k);
    for (auto& i : bag) cin >> i;

    sort(bag.begin(), bag.end());
    priority_queue<int> pq;

    int curr = 0;
    ll ans = 0;
    int bi = 0;
    
    while (bi < k) {

        while (curr <= bag[bi]) {
            for (int i : jewel[curr]) pq.push(i);
            curr++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        
        bi++;
        if (bi == k) break;
    }

    cout << ans;
}
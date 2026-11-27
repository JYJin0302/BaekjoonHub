#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;

    vector<ll> chick(n);
    for (auto& i : chick) cin >> i;

    vector<pair<ll, ll>> cow(m);
    for (auto& i : cow) cin >> i.x >> i.y;

    sort(chick.begin(), chick.end());
    sort(cow.begin(), cow.end());

    ll ans = 0, i1 = 0, i2 = 0;
    
    priority_queue<pair<ll, ll>> pq;
    
    while(i1 < n){
        
        while(i2 < m && cow[i2].x <= chick[i1]) {
            pq.push({-cow[i2].y, cow[i2].x});
            i2++;
        }
        
        while(!pq.empty() && !(-pq.top().x >= chick[i1] && pq.top().y <= chick[i1])) pq.pop();
        
        if (!pq.empty()) {
            ans++;
            pq.pop();
        }
        
        i1++;
    }

    cout << ans;
}
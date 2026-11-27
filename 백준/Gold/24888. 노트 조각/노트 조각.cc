#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> adj[200001];

const ll inf = 1e15;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    while(m--){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    vector<int> isT(n+1);
    for(int i = 1; i <= n; i++) cin >> isT[i];
    
    vector<int> cnt(n+1), from(n+1);
    vector<ll> dist(n+1, inf);
    dist[1] = 0;
    vector<bool> v(n+1);
    
    cnt[1] = isT[1];
    priority_queue<pair<ll, ll>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        
        ll a, b;
        tie(a, b) = pq.top();
        pq.pop();
        
        if (v[b]) continue;
        v[b] = 1;
        
        for (auto i : adj[b]){
            ll x, y;
            tie(x, y) = i;
            
            if(!v[x]) {
                if (dist[x] >= dist[b] + y){
                    if (dist[x] == dist[b] + y) {if(cnt[x] <= cnt[b] + isT[x]){
                        cnt[x] = cnt[b] + isT[x];
                        from[x] = b;
                        pq.push({a-y, x});
                    }
                }
                    else {
                        cnt[x] = cnt[b] + isT[x];
                        dist[x] = dist[b] + y;
                        from[x] = b;
                        pq.push({a-y, x});
                    }
                }
            }
        }
    }
    
    int tot = 0;
    for(auto i : isT) tot += i;
    
    if (tot != cnt[n]) cout << -1;
    else{
        
        int c = n;
        vector<int> ans;
        
        while(c) {
            ans.push_back(c);
            c = from[c];
        }
        reverse(ans.begin(), ans.end());
        
        cout << ans.size() << '\n';
        for (auto i : ans) cout << i << ' ';
    }
}
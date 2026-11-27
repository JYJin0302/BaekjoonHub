#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++){

        ll n, k;
        cin >> n >> k;
        
        map<ll, ll> cnt;
        cnt.clear();
        
        cnt[n] = 1;
        ll tot = 0;
        priority_queue<ll> pq;
        pq.push(n);
        while(!pq.empty()){
            
            ll a = pq.top();
            pq.pop();
            
            ll a1, a2;
            a1 = (a-1)/2;
            a2 = a-1-a1;
            
            tot += cnt[a];
            if (tot >= k || a == 0){
                // answer
                cout << "Case #" << tc << ": ";
                if (a == 0) cout << "0 0\n";
                else cout << max(a1, a2) << ' ' << min(a1, a2) << '\n';
                break;
            }
            
            if (cnt[a1] == 0) pq.push(a1);
            cnt[a1] += cnt[a];
            if (cnt[a2] == 0) pq.push(a2);
            cnt[a2] += cnt[a];
            cnt[a] = 0;
        }
        while(!pq.empty()) pq.pop();
        
    }
    
}
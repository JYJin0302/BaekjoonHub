#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<ll> A(n), B(n);
    for(auto&i  : A) cin >> i;
    
    ll min_val = 0, t = 0;
    priority_queue<pair<ll, ll>> pq;
    
    pq.push({A[0], 0});
    for(int i = 1; i < n; i++){
        
        t++;
        ll x = A[i];
        ll min_pos = pq.top().first + t;
        B[i-1] = min_pos - 1;
        
        if (x >= min_pos) pq.push({x - t, t});
        else{
            min_val += min_pos - x;
            pq.push({x-t, t});
            pq.pop();
            pq.push({x-t, t});
        }
    }
    
    vector<ll> ans;
    for(int i = n-1; i >= 0; i--){
        ll pv = 3e9;
        if (!ans.empty()) pv = ans.back() - 1;
        
        while(!pq.empty() && (pq.top().second > i || pq.top().first+i > pv)) pq.pop();
        
        if (pv <= B[i]) ans.push_back(pv);
        else if (!pq.empty()) ans.push_back(pq.top().first + i);
        else ans.push_back(pv);
    }
    
    reverse(ans.begin(), ans.end());
    for(auto i : ans) cout << i << '\n';
}
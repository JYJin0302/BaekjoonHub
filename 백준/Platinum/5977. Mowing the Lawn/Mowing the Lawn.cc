#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
        
    ll n, l;
    cin >> n >> l;
    l++;
    
    vector<ll> dp(n+2);
    
    deque<pair<ll, ll>> dq;
    dq.push_back({0, -1});
    ll tot = 0;
    for (int i = 0; i <= n; i++){
        ll num = 0;
        if (num != n) cin >> num;
        tot += num;
        
        while(!dq.empty() && i - dq.front().y > l) dq.pop_front();
        dp[i] = dq.front().x+num;
        while(!dq.empty() && (dq.back().x > dp[i] || i - dq.back().y > l)) dq.pop_back();
        dq.push_back({dp[i], i});
    }
    
    cout << tot - dp[n];
}
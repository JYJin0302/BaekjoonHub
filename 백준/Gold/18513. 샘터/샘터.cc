#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct p{
    bool operator()(const pair<ll, ll>& a,const pair<ll, ll>& b){
        return abs(a.second) > abs(b.second);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n >> k;
    
    map<ll, bool> used;
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, p> pq;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        
        pq.push({a, 1});
        pq.push({a, -1});
        used[a] = 1;
    }
    
    int cnt = 0;
    ll val = 0;
    
    while(!pq.empty() && cnt < k){
        ll a, b, nb;
        tie(a, b) = pq.top();
        
        pq.pop();
        
        if (b > 0) nb = b + 1;
        else nb = b-1;
        
        if (!used[a+b]){
            used[a+b] = 1;
            cnt++;
            val += abs(b);
            if (!used[a + nb]) pq.push({a, nb});
        }
        else continue;
    }
    
    cout << val;
}
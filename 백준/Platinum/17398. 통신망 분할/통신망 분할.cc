#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

vector<ll> root, num;
ll find(int n){
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}
int main(){
    
    ll n, m, q;
    cin >> n>> m >> q;
    
    num = vector<ll> (n+1, 1);
    root = vector<ll> (n+1);
    for(int i = 1; i <= n ; i++) root[i] = i;
    
    vector<pair<ll, ll>> A(m+1);
    for(int i = 1; i <= m; i++) cin >> A[i].x >> A[i].y;
    
    vector<ll> query;
    vector<bool> cut(m+1);
    while(q--){
        ll a;
        cin >> a;
        cut[a] = 1;
        query.push_back(a);
    }
    
    reverse(query.begin(), query.end());
    
    for(int i = 1; i <= m; i++){
        if (!cut[i]){
            ll a, b;
            tie(a, b) = A[i];
            
            a = find(a), b = find(b);
            if (a != b){
                num[a] += num[b];
                root[b] = a;
            }
        }
    }
    
    ll ans = 0;
    for(auto i : query){
        ll a, b;
        tie(a, b) = A[i];
        
        a = find(a), b = find(b);
        
        if (a != b){
            ans += num[a] * num[b];
            num[a] += num[b];
            root[b] = a;
        }
    }
    
    cout << ans;
}
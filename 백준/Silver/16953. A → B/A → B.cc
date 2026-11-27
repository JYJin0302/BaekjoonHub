#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ll a, b, x, y;
    cin >> a >>b;
    
    queue<pair<ll ,ll>> q;
    
    ll ans = -1;
    q.push({0, a});
    while(!q.empty()){
        tie(x, y) = q.front();
        q.pop();
        if (y > b) continue;
        if (y == b) {
            ans = x + 1;
            break;
        }
        q.push({x+1, y*2});
        q.push({x+1, y*10 + 1});
    }
    cout << ans;
}
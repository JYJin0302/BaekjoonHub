#include <iostream>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    ll res = 0;
    for(int i = 0; i < n; i++){
        ll tot = 0;
        for(int j = 0; j < m; j++){
            ll x;
            cin >> x;
            tot += x;
        }
        
        res ^= tot;
    }
    
    if(res != 0) cout << "august14";
    else cout << "ainta";
}
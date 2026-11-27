#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
typedef long long ll;

bool cmp(string v1, string v2){
    if((int)v1.size() != (int)v2.size()){
        return (int)v1.size() < (int)v2.size();
    }

    for(int i =0 ; i< (int)v1.size(); i++){
        if(v1[i] != v2[i]) return v1[i] < v2[i];
    }
    return 1;
}

void solve(){
    
    ll x;
    cin >> x;

    string ans= to_string(x);
    for(ll v = 1; v < x; v *= 10){
        ll v1 = x - v;
        ll v2 = v;
        string res = to_string(v1) + to_string(v2);

        if(cmp(ans, res)) ans= res;
    }
    cout << ans << '\n';

}

int main(){ 
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
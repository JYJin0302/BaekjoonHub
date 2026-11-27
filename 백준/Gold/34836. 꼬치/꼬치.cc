#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i :A )cin >> i;

    vector<bool> tmp(n+10);
    int ix = 0;

    vector<bool> chk(n+10);
    for(int i =0 ;i < n; i++){
        tmp[A[i]] = 1;
        while(tmp[ix+1]) ix++;
        if (ix == i+1) chk[i] = 1;
    }

    int mx = 0;
    int cnt = 1;
    for(int i = 0; i < n;i++){
        if(chk[i]) cnt++;
        else cnt = 0;
        mx = max(mx, cnt);
    }
    
    cout << 2 * (n - mx + 1) << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
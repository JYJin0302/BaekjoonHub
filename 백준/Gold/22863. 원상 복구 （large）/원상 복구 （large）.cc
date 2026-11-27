#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, k;
    cin >> n>> k;
    vector<ll> A(n), B(n+1), Bi(n+1);
    for(auto& i : A) cin >> i;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        B[i] = x;
        Bi[x] = i;
    }
    
    vector<int> ans(n+1);
    vector<bool> v(n+1);
    for(int i = 1; i <= n; i++){
        if (v[i]) continue;
        v[i] = 1;
        
        int cyc_len = 1;
        int ti = Bi[i];
        vector<int> tmp;
        tmp.push_back(i);
        while(ti != i){
            v[ti] = 1;
            tmp.push_back(ti);
            cyc_len++;
            ti = Bi[ti];
        }
        
        ll d = k % cyc_len;
        
        for(int j = 0; j < cyc_len; j++){
            int nti = tmp[(j + d) % cyc_len];
            ans[ti] = A[nti-1];
            ti = Bi[ti];
        }
    }
    
    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
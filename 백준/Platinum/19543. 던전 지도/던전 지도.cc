#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n>> m >> k;
    
    vector<string> A(k);
    for(auto& i : A) cin >> i;
    
    string rt;
    cin >> rt;
    
    reverse(rt.begin(), rt.end());
    
    ll ans = 0;
    int l = m-2, r = m-1;
    int num = rt[0] - 'A';
    while(l >= 0 && A[num][l] == 'R') l--;
    ans += r - l;
    
    int idx = 1;
    while(idx < n){
        
        num = rt[idx] - 'A';
        
        while(r >= 0 && A[num][r] != 'U') r--;
        if (r <= l) break;
        
        while(l >= 0 && A[num][l] != 'U') l--;
        
        ans += r - l;
        idx++;
    }
    
    cout << ans;
}
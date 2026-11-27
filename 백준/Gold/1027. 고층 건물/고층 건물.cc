#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> A(n);
    for(auto& i : A) cin >> i;
    
    int res = 0;
    for (int i = 0; i < n; i++){
        
        int ans = 0;
        ll den = 1, num = -1e9;
        
        // right side
        for (int j = i+1; j < n; j++){
            ll td = j-i;
            ll tn = A[j] - A[i];
            
            if (num*td < den*tn) {
                ans++;
                den = td;
                num = tn;
            }
        }
        
        // left side
        
        den = 1, num = -1e9;
        for (int j = i-1; j >= 0; j--){
            ll td = i - j;
            ll tn = A[j] - A[i];
            
            if (num*td < den*tn) {
                ans++;
                den = td;
                num = tn;
            }
        }
        
        res = max(res, ans);
    }
    cout << res;
}
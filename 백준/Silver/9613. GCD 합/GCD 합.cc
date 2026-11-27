#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int GCD(int n, int m){
    if (m == 0) return n;
    return GCD(m, n%m);
}



int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        
        vector<int> base(n);
        for(auto& i : base) cin >> i;
        ll ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                ans += GCD(max(base[i], base[j]), min(base[i], base[j]));
            }
        }
        cout << ans << '\n';
    }
    
    
}
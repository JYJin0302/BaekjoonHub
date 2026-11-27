#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int tot = 0, ans = 0;
    for(int i = 0; i < n; i++){
        bool p;
        cin >> p;
            
        tot += A[i];
        ans += A[i]*(1-p);
    }
    cout << tot << '\n' << ans;
}
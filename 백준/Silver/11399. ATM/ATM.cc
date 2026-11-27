#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> base(n);
    for (auto& i : base) cin >> i;
    
    sort(base.begin(), base.end());
    
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += base[i] * (n-i);
    }
    
    cout << ans;
}
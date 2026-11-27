#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, ans = 2000000000;
    cin >> n >> m;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    sort(A.begin(), A.end());
    int l = 0, r = 1;
    
    if (m == 0) {
        cout << 0;
        return 0;
    }
    
    while(r < n){
        int v = A[r] - A[l];
        if (v >= m) {
            ans = min(ans, v);
            l++;
        }
        else r++;
    }
    
    cout << ans;
}
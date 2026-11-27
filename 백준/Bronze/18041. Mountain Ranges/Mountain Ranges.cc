#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int ans = 1;
    for(int i =0 ; i < n;i++){
        int ix= i;
        while(ix +1 < n && A[ix+1] - A[ix]<= x) ix++;
        ans = max(ans, ix-i+1);
    }
    cout << ans;
    
}
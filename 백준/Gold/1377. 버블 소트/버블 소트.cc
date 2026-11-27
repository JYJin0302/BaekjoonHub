#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        A[i] = {x, i};
    }
    
    sort(A.begin(), A.end());
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, A[i].second - i);
    }
    
    cout << ans+1;
    
}
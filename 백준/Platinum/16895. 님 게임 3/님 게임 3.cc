#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n), B(n);
    for(auto& i : A) cin >> i;
    
    int res = 0;
    for(auto i : A) res ^= i;
    
    if (n == 1) cout << 1;
    else if (res == 0) cout << 0;
    else{
        
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if ((res ^ A[i]) <= A[i]) cnt++;
        }
        cout << cnt;
        
    }
}
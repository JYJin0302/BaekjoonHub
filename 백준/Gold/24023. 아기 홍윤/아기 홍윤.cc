#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    int pi = 0, pv = 0;
    for (int i = 0; i < n; i++){
        
        int x = A[i];
        
        bool ok = 1;
        for (int i = 0; i < 30; i++){
            if (((x & (1 << i)) > 0) && (k & (1 << i)) == 0) ok = 0;
        }
        
        if (!ok){
            pi = i+1;
            pv = 0;
        }
        else{
            pv |= x;
            if (pv == k){
                cout << pi+1 << ' ' << i+1 << '\n';
                return 0;
            }
        }
    }
    cout << -1;
    
}
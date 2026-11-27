#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++){
        
        int n;
        cin >> n;
        
        vector<int> A(n);
        for(auto& i : A) cin >> i;
        
        int ans = 0;
        for (int i = 0; i < n; i++){
            int v = A[i], ix = i;
            for (int j = i+1; j < n; j++){
                if (v > A[j]) {
                    v = A[j];
                    ix = j;
                }
            }
            ans += ix - i + 1;
            int l = i, r = ix;
            while(l <= r){
                swap(A[l], A[r]);
                l++, r--;
            }
        }
        cout << "Case #" << tc << ": " << ans-1 << '\n';
    }
    
}
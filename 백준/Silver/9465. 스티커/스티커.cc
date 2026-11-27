#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
     cin >> t;
    while(t--){
        cin >> n;
        
        vector<int> u(n);
        for(auto& i : u) cin >> i;
        vector<int> d(n);
        for (auto& i : d) cin >> i;
        
        vector<int> dpu(n+1);
        vector<int> dpd(n+1);
        
        dpu[1] = u[0];
        dpd[1] = d[0];
        
        for (int i = 2; i<=n;i++){
            dpu[i] = max(dpd[i-2], dpd[i-1]) + u[i-1];
            dpd[i] = max(dpu[i-2], dpu[i-1]) + d[i-1];
        }
        
        cout << max(dpu[n], dpd[n]) << endl;
    }

}
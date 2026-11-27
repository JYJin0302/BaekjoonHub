#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, n, n1, n2;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> base(n+1);
        for (int i = 0; i < n; i++){
            cin >> n1 >> n2;
            base[n1] = n2;
        }
        
        int mini = base[1];
        int ans = 1;
        for (int i = 2; i <= n; i++){
            if (base[i] < mini) {ans++; mini = base[i];}
        }
        
        cout << ans << endl;
        
    }
}
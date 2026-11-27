#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        
        vector<string>A(n);
        for(auto& i : A) cin >> i;
        
        sort(A.begin(), A.end());
        
        bool ok = true;
        for (int i = 1; i < n; i++){
            string a = A[i-1];
            string b = A[i];
            
            bool check = false;
            for (int k = 0; k < min(a.size(), b.size()); k++){
                if (a[k] != b[k]) check = true;
            }
            
            ok = ok & check;
        }
        
        if (ok) cout << "YES\n";
        else cout << "NO\n";
        
    }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    while(cin >> n){
        
        vector<int> A;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            
            int ix = lower_bound(A.begin(), A.end(), x) - A.begin();
            
            if (ix == A.size()) A.push_back(x);
            else A[ix] = x;
        }
        
        cout << A.size() << '\n';
    }
}
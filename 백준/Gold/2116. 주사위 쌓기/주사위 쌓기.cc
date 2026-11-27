#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int>> A(n);
    for(int i = 0; i < n;i ++){
        vector<int> t(6);
        cin >> t[0] >> t[1] >> t[2] >> t[4] >> t[5] >> t[3];
        A[i] = t;
    }
    
    int ans = 0;
    for (int i = 1; i <= 6; i++){
        int val = 0;
        int pv = i;
        
        for (int j = 0; j < n; j++){
            
            int it = find(A[j].begin(), A[j].end(), pv) - A[j].begin();
            if (A[j][it] + A[j][(it + 3) % 6] == 11) val += 4;
            else if (max(A[j][it], A[j][(it+3)%6]) == 6) val += 5;
            else val += 6;
            pv = A[j][(it+3)%6];
        }
        ans=  max(ans, val);
    }
    cout << ans;
}
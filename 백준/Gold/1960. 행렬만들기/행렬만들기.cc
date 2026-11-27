#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> R(n);
    vector<int> C(n);
    
    for(auto& i : C) cin >> i;
    for(int i = 0; i < n; i++) {
        cin >> R[i].x;
        R[i].x *= -1;
        R[i].y = i;
    }
    
    int ans[501][501];
    
    bool ok = 1;
    for (int i = 0; i < n; i++){
        
        sort(R.begin(), R.end());
        int x = C[i];
        
        int ix = 0;
        while(ix < n && x > 0){
            if (R[ix].x == 0) {
                break;
            }
            
            ans[i][R[ix].y] = 1;
            R[ix].x++;
            x--, ix++;
        }
        if (x != 0) {
            ok = 0;
            break;
        }
    }
    
    for (auto i : R) {
        if (i.x != 0) ok = 0;
    }
    
    if(ok){
        cout << "1\n";
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                 cout << ans[i][j];
            }
            cout << '\n';
        }
    }
    else cout << -1;
}
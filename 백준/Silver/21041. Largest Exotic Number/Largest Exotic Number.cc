#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<int> pos(100001, -1);
    
    int ans = -1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x;
            cin >> x;
            
            if (pos[x] == -1) pos[x] = j;
            else if (pos[x] > j) pos[x] = j;
            else ans = max(ans, x);
        }
    }
    
    cout << ans;
    
}
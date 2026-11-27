#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int ans[1001][1001];
    
    int c = 1;
    for (int j = 1; j < n; j++){
        int p = j%2;
        ans[j][0] = ans[j-1][0] + c * (2*p - 1);
        c++;
    }
    
    for(int j = 1; j < m; j++){
        for (int i = 0; i < n; i++){
            int p = (i+j)%2;
            ans[i][j] = ans[i][j-1] + c*(2*p - 1);
            
            c++;
        }
        c += n-1;
    }
    
    int mv = 0;
    for (int i = 0;  i <n ;i ++){
        for (int j = 0; j < m; j++){
            mv = min(mv, ans[i][j]);
        }
    }
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << ans[i][j] - mv + 1 << ' ';
        }
        cout << '\n';
    }
}
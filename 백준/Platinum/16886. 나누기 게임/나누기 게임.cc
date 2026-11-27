#include <bits/stdc++.h>
using namespace std;

int g[100001];
int ans[100001];
int solve(int x){
    
    if (g[x] != -1) return g[x];
    if (x == 1) return g[x] = 0;
    
    vector<int> cnt(20);
    
    for(int k = 2; k <= x; k++){
        // k 더미로 나누기
        if (k % 2 == 0){
            int tk = x/k;
            
            int mx = tk - k/2 + 1;
            if (mx < 1) break;
            if ((tk*2+1) * (k/2) == x && mx >= 1){
                int r = 0;
                for (int i = mx; i < mx + k; i++){
                    r ^= solve(i);
                }
                if (ans[x] == -1 && r == 0) ans[x] = k;
                cnt[r]++;
            }
        }
        else{
            
            int tk = x/k;
            int mx = tk - k/2;
            
            if (mx < 1) break;
            if (tk*k == x && mx >= 1){
                int r = 0;
                for(int i = mx; i < mx+k; i++){
                    r ^= solve(i);
                }
                if (ans[x] == -1 && r == 0) ans[x] = k;
                cnt[r]++;
            }
            
        }
        
    }
    
    int res = 0;
    while(cnt[res])res++;
    return g[x] = res;
}

int main(){
    
    memset(g, -1, sizeof(g));
    memset(ans, -1, sizeof(ans));
    
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) solve(i);
    
    cout << ans[n];
}
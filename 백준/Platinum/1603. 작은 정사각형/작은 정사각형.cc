#include <bits/stdc++.h>
using namespace std;

int n, m;
int g[1 << 20];

bool isB(int b, int i){
    return (b & (1 << i)) > 0;
}

int solve(int b){
    if (g[b] != -1) return g[b];
    if (b == (1 << 20) - 1) return g[b] = 0;
    
    
    vector<int> cnt(100);
    for(int i = 0; i < 20; i++){
        if (!isB(b, i)) cnt[solve(b | (1 << i))]++;
    }
    
    for(int i = 1; i < 10; i++){
        if (!isB(b, i) && !isB(b, i-1) && !isB(b, i+10) && !isB(b, i+9)){
            int tb = b;
            tb |= (1 << i);
            tb |= (1 << i-1);
            tb |= (1 << i+10);
            tb |= (1 << i+9);
            cnt[solve(tb)]++;
        }
    }
    
    int r = 0;
    while(cnt[r] != 0) r++;
    return g[b] = r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(g, -1, sizeof(g));
    
    int t_c = 3;
    while(t_c--){
        int n, m;
        cin >> n >> m;
        
        int r = 0;
        for(int i = 0; i < n; i += 2){
            string s;
            int b = 0;
            
            cin >> s;
            for(int j = 0; j < m; j++){
                b = b*2 + (s[j] == '#');
            }
            
            int cc = 10 - m;
            while(cc--) b = b*2+1;
            
            if (i == n-1){
                for(int j = 0; j < m; j++){
                    b = b*2 + 1;
                }
            }
            else{
                cin >> s;
                for(int j = 0; j < m; j++){
                    b = b*2 + (s[j] == '#');
                }
            }
            cc = 10 - m;
            while(cc--) b = b*2+1;
            
            r ^= solve(b);
        }
        
        if (r != 0) cout << "Y\n";
        else cout << "M\n";
    }
}
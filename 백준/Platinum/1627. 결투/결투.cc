#include <bits/stdc++.h>
using namespace std;

int g[3001];
int solve(int x){
    if (x <= 0) return 0;
    if (g[x] != -1) return g[x];
    
    vector<int> cnt(201);
    for(int i = 1; i <= x; i++){
        int tx = solve(i-3)^solve(x - i-2);
        if (tx <= 200) cnt[tx]++;
    }
    
    int r = 0;
    while(cnt[r]) r++;
    return g[x] = r;
}

int main(){
    
    int n;
    cin >> n;
    
    memset(g, -1, sizeof(g));
    
    string s;
    cin >> s;
    
    string ts = ".." + s + "..";
    // test win-in-1
    int pv = 1;
    vector<int> ans, A;
    for (int i = 2; i < n+2; i++){
        bool ok = 0;
        if (ts[i-2] == 'P' && ts[i-1] == 'P') ok = 1;
        if (ts[i-1] == 'P' && ts[i+1] == 'P') ok = 1;
        if (ts[i+1] == 'P' && ts[i+2] == 'P') ok = 1;
        if (ok) ans.push_back(i-1);
        
        if (ts[i] == 'P') {
            int tx = max(0, i-3 - pv);
            if (tx != 0) A.push_back(tx);
            pv = i+2;
        }
    }
    if (!ans.empty()){
        cout << "WINNING\n";
        for (int i : ans) cout << i << ' ';
        return 0;
    }
    
    for(int i = 0; i < n; i++){
            
        if (s[i] == 'P') continue;
            
        int pv = -3;
        s[i] = 'P';
        bool ok = 1;
        int r = 0;
        for (int j = 0; j < n; j++){
            if (s[j] == 'P'){
                int d = j - pv - 5;
                if (d <= -3) ok = 0;
                d = max(0, d);
                r ^= solve(d);
                pv = j;
            }
        }
        int d = n+2 - pv - 5;
        d = max(0, d);
        r ^= solve(d);
        
        if (ok && r == 0) ans.push_back(i+1);
        s[i] = '.';
    }
    
    if (ans.empty()) cout << "LOSING";
    else {
        cout << "WINNING\n";
        for (int i : ans) cout << i << ' ';
    }
}
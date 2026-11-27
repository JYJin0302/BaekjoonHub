#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s, e;
    cin >> s >> e;
    
    vector<int> cnt_s(10), cnt_e(10);
    for(char c : s) cnt_s[c-'0']++;
    for(char c : e) cnt_e[c-'0']++;
    
    int n = s.size();
    
    int ix = 0;
    int rs = n - e.size();
    for (int i = 0; i <rs; i++){
        
        // test from 9 -> 1
        for (int t= 9; t >= 1; t--){
            if (cnt_s[t] == cnt_e[t]) continue;
            
            int tx = ix;
            vector<int> tmp(10);
            while(tx < n && s[tx] - '0' != t){
                tmp[s[tx] - '0']++;
                tx++;
            }
            
            bool ok = (tx != n);
            for (int k = 1; k <= 9; k++){
                if (tmp[k] > cnt_e[k]) ok = 0;
            }
            
            if (ok){
                cout << t;
                for (int k = 1; k <= 9; k++){
                    cnt_s[k] -= tmp[k];
                    cnt_e[k] -= tmp[k];
                }
                cnt_s[t]--;
                ix = tx + 1;
                break;
            }
        }
    }
    
    
}
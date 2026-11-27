#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> pond(2*n+1);
    int blank = n;
    
    vector<pair<int, int>> ans;
    
    int cnt = 1;
    int phase = 1;
    while(cnt <= n){
        
        for (int i = 1; i <= cnt; i++) ans.push_back({phase, i});
        cnt++;
        phase = 3 - phase;
        
    }
    
    cnt--;
    for (int i = 1; i <= cnt; i++) ans.push_back({phase, i});
    phase = 3 - phase;
    
    cnt = 0;
    while(1 + cnt <= n){
        
        for (int i = 1 + cnt; i <= n; i++) ans.push_back({phase, i});
        cnt++;
         phase = 3 - phase;
    }
    
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << i.first << ' ' << i.second << '\n';
    }
    
}
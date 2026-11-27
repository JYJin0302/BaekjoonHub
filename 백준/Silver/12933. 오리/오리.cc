#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    int n = s.size();
    
    int ans = 0;
    vector<int> cnt(5);
    bool ok = 1;
    for (char c : s){
        if (c == 'q') cnt[0]++;
        else if (c == 'u'){
            cnt[0]--;
            cnt[1]++;
        }
        else if (c == 'a'){
            cnt[1]--;
            cnt[2]++;
        }
        else if (c == 'c'){
            cnt[2]--;
            cnt[3]++;
        }
        else cnt[3]--;
        
        int v = 0;
        for (int i : cnt){
            if (i < 0) ok = 0;
            v += i;
        }
        
        ans = max(ans, v);
    }
    
    for (int i : cnt) if (i > 0) ok = 0;
    if (!ok) cout << -1;
    else cout << ans;
}
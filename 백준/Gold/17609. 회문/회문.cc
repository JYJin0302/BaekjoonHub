#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while(n--){
        string s;
        cin >> s;
        
        int m = s.size();
        
        int l = 0, r = m-1;
        while(l <= r && s[l] == s[r]) l++, r--;
        
        int ans = 2;
        if (l > r) ans = 0;
        else {
            // test l+1, r
            int tl = l+1, tr = r;
            while(tl <= tr && s[tl] == s[tr]) tl++, tr--;
            if (tl > tr) ans = 1;
            
            // test l, r-1
            tl = l, tr = r-1;
            while(tl <= tr && s[tl] == s[tr]) tl++, tr--;
            if (tl > tr) ans = 1;
        }
        
        cout << ans << '\n';
    }
}
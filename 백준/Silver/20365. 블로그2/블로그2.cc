#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
string s;

void solve(int l, int r){
    if (l > r) return;
    ans++;
    
    int tl = l, tr = r;
    while(tl < n && s[tl] == s[l]) tl++;
    while(tr >= 0 && s[tr] == s[r]) tr--;
    
    solve(tl, tr);
}

int main(){
    
    cin >> n;
   
    cin >> s;
    
    int l = 0, r = n-1;
    while(s[l] != s[r]) r--;
    
    if (r != n-1) ans++;
    
    solve(l, r);
    cout << ans;
}
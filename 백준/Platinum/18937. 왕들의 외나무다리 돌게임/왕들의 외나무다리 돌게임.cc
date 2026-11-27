#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int res = 0;
    while(n--){
        int x;
        cin >> x;
        
        res ^= x-2;
    }
    
    string s;
    cin >> s;
    
    string ans[2] = {"Whiteking", "Blackking"};
    int ix = 0;
    if (ans[ix] != s) ix++;
    
    ix ^= (1 - (res > 0));
    cout << ans[ix];
}
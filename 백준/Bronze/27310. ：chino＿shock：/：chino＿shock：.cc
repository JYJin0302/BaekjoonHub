#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int ans = 0;
    for(auto i : s){
        ans++;
        if (i == '_') ans += 5;
        if (i == ':') ans++;
    }
    cout << ans;
}
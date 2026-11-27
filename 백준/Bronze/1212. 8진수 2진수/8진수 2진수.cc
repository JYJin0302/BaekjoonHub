#include <bits/stdc++.h>
using namespace std;


int main() {
    
    string s;
    cin >> s;
    
    if (s == "0"){
        cout << 0;
        return 0;
    }
    
    vector<int> ans;
    for(int i = 0; i < s.size(); i++){
        ans.push_back((s[i] - '0') / 4);
        ans.push_back(((s[i] - '0') % 4) / 2);
        ans.push_back((s[i] - '0') % 2);
    }
    
    int ix = 0;
    while(ix < ans.size() && ans[ix] == 0) ix++;
    for(; ix < ans.size(); ix++) cout << ans[ix];
    
    
}
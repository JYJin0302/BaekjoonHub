#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int m, n;
    cin >> m >> n;
    
    if (m == 0){
        cout << 0;
        return 0;
    }
    
    vector<char> ans;
    while(m){
        
        int val = m%n;
        if (val < 10) ans.push_back(char('0' + val));
        else ans.push_back(char('A' + val - 10));
        
        m /= n;
    }
    reverse(ans.begin(), ans.end());

    
    for(auto i : ans) cout << i;
    
}
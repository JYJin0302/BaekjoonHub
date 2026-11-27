#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    string s;
    cin >> n >> m;
    map<string, int> mp;
    while(n--) {
        cin >> s;
        mp[s] = 1;
    }
    vector<string> ans;
    while(m--){
        cin >> s;
        
        if (mp[s] > 0) ans.push_back(s);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << '\n';
}
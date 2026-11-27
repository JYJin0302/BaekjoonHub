#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n; 
    string s1, s2;
    cin >> t;
    while (t--){
        cin >> n;
        map<string, int> mp;
        while(n--){
            cin >> s1 >> s2;
            mp[s2]++;
        }
        
        map<string, int> ::iterator iter;
        int ans = 1;
        for (iter = mp.begin(); iter != mp.end(); iter++) ans *= (*iter).second + 1;
        cout << ans - 1 << endl;
    }


}
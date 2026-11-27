#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    int t;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        
        cout << "Case #" << tc << ": ";
        string s;
        cin >> s;
        
        int n = s.size();
        bool ok = 1;
        
        for (int i = 1; i < n; i++){
            if (s[i] - s[i-1] < 0) {
                ok = 0;
                
                int j = i-1;
                while(j >= 0 && s[j] == s[i-1])j--;
                j++;
                
                s[j]--;
                for (int k = j+1; k < n; k++) s[k] = '9';
                
                for (int j = 0; j < n; j++){
                    if (j == 0 && s[j] == '0') continue;
                    else cout << s[j];
                }
                cout << '\n';
            }
        }
        
        if (ok) cout <<s << '\n';
    }
    
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    
    cin >> n;
    while(n--){
        cin >> s;
        
        stack<char> vps;
        
        bool ok = true;
        for (char i : s) {
            if (i == ')'){
                if (vps.empty() || vps.top() != '('){ok = false; break;}
                vps.pop();
            }
            else {
                vps.push(i);
            }
        }
        
        if (!vps.empty()) ok = false;
        cout << (ok ? "YES\n" : "NO\n");
        
    }

}
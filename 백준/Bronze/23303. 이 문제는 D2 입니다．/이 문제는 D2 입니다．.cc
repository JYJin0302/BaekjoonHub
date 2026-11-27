#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin, s);
    
    bool ok = 0;
    for (int i = 1; i < s.size(); i++){
        if (s[i] == '2' && (s[i-1] == 'D' || s[i-1] == 'd')) ok = 1;
    }
    if (ok) cout << "D2";
    else cout << "unrated";
    
}
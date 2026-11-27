#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int cntA = 0, cntB = 0, cntC = 0;
    for(char c : s) {
        if (c == 'A') cntA++;
        else if (c == 'B') cntB++;
        else if (c == 'C') cntC++;
    }
    
    if (cntA != 0){
        for (int i = 0; i < s.size(); i++){
            if (s[i]=='B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'F') s[i] = 'A';            
        }
    }
    else if( cntB != 0){
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'C' || s[i] == 'D' || s[i] == 'F') s[i] = 'B';            
        }
    }
    else if (cntC != 0){
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'D' || s[i] == 'F') s[i] = 'C';            
        }
    }
    else{
        for (int i = 0; i < s.size(); i++) s[i] = 'A';
    }
    
    cout << s;
    
}
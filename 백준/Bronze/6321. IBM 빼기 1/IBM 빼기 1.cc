#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    for(int i =1 ; i<= t; i++){
        if (i != 1) cout << '\n';
        string s;
        cin >> s;
        
        for(char& c : s){
            c = c + 1;
            if (c > 'Z') c -= 26;
        }
        
        cout << "String #" << i << '\n';
        cout << s << '\n';
    }
}
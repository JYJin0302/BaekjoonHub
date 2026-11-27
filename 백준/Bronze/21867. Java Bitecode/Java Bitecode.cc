#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int cnt = 0;
    for (char  c : s){
        if (c != 'J' && c != 'A' && c != 'V'){
            cnt++;
            cout << c;
        }
    }
    
    if (cnt == 0) cout << "nojava";
    
}
#include <bits/stdc++.h>
using namespace std;

int main(){
   
    string s1, s2;
    cin >> s1 >> s2;
    
    int ans = 0;
    int m1 = stoi(s1.substr(3, 2));
    int m2 = stoi(s2.substr(3, 2));
    
    int h1 = stoi(s1.substr(0, 2));
    int h2 = stoi(s2.substr(0, 2));
    
    if (m1 != m2){
        
        if (m1 < m2) ans += m2-m1;
        else {
            h1 = (h1 + 1) % 24;
            ans += m2-m1+60;
        }
    }
    
    if (h1 != h2){
        if (h1 < h2) ans += h2-h1;
        else ans += 24 +h2-h1;
    }
    cout << ans;
    
    
}

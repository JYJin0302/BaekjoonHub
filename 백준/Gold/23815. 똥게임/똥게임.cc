#include <bits/stdc++.h>
using namespace std;

int cal(int x, string s){
    if (s[0] == '+') return x + (s[1] - '0');
    if (s[0] == '-') return x - (s[1] - '0');
    if (s[0] == '*') return x * (s[1] - '0');
    if (s[0] == '/') return x / (s[1] - '0');
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    int a1 = 1, a2 = 1;
    
    for(int i = 0; i < n; i++){
        
        string s1, s2;
        cin >> s1 >> s2;
        
        int na1 = max(cal(a1, s1), cal(a1, s2));
        if (a1 <= 0) na1 = 0;
        a2 = max({a1, cal(a2, s1), cal(a2, s2)});
        a1 = na1;
        
        if (a1 <= 0 && a2 <= 0){
            cout << "ddong game";
            return 0;
        }
    }
    
    cout << max(a1, a2);
    
}
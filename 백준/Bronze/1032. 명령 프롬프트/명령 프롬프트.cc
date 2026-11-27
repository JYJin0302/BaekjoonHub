#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int m = s.size();
    for(int i = 0; i < n-1; i++){
        string s1;
        cin >> s1;
        
        for(int j = 0; j < m; j++){
            if (s[j] != s1[j]) s[j] = '?';
        }
    }
    cout << s;
}
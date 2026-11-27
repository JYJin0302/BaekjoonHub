#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,m;
    cin >> n >> m;
    
    string s= to_string(n);
    int k = s.size();
    
    int cnt = 0, i = 0;
    m = min(m, k*n);
    
    while(cnt < m){
        cout << s[i];
        i = (i+1)%s.size();
        cnt++;
    }
}
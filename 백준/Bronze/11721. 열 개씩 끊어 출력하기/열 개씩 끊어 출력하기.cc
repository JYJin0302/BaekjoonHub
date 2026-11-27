#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int n = 0;
    while(n < s.size()){
        cout << s.substr(n, 10) << '\n';
        n += 10;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int ix = 0;
    while(ix < s.size() && s[ix] == s[0]) ix++;
    cout << ix;
    
}
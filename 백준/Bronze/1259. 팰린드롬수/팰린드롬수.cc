#include <bits/stdc++.h>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    while(s != "0"){
        string t = s;
        reverse(t.begin(), t.end());
        cout << (t == s ? "yes\n" : "no\n");
        cin >> s;
    }
}
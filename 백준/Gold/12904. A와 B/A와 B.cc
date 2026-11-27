#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    
    while(b.size() > a.size()){
        int n = b.size();
        if(b.back() == 'A'){
            b=b.substr(0, n-1);
        }
        else{
            b=b.substr(0, n-1);
            reverse(b.begin(), b.end());
        }
    }
    cout << int(a==b);
}
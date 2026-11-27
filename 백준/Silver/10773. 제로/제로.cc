#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, inp;
    cin >>n;
    int ans = 0;
    stack<int> base;
    for (int i = 0 ;i < n; i++){
        cin >> inp;
        if (inp == 0) {ans -= base.top();base.pop();}
        else {base.push(inp); ans += inp;}
    }
    
    cout << ans;
}
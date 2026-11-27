#include <bits/stdc++.h>
using namespace std;

int main(){
    int e, s, m;
    cin >> e>> s >> m;
    int ans = 1;
    
    while(!(e == 1 && s == 1 && m == 1)){
        ans++;
        e --;
        s --;
        m --;
        if (e == 0) e+= 15;
        if (s == 0) s += 28;
        if (m == 0) m += 19;
    }
    cout << ans;
}
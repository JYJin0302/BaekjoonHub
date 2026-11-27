#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    int ai = 0, ans = 10001;
    
    for(int i = 1; i <= t; i++){
        int a, b;
        cin >> a >> b;
        
        int ta = (a-1) / (b+1) + 1;
        if (ta*2 < ans) {
            ans = ta*2;
            ai = i;
        }
    }
    
    cout << ai << ' ' << ans;
}
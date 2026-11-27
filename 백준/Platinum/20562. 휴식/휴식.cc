#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        int n, m, x;
        cin >> n >> m >> x;
        
        if (n > m-3) cout << "0\n";
        else{
            
            int l = 1, r = m-1;
            l = (l - n + m) % m;
            r = (r - n*2 + m) % m;
            
            x %= m;
            int res = 0;
            if (l <= r) {
                if (l <= x && x <= r) res = x - l + 1 - (x == r);
            }
            else {
                if (x >= l) res = x - l + 1;
                else if (x <= r) res = m - l + x + 1 - (x == r);
            }
            
            cout << res << '\n';
        }
    }
}
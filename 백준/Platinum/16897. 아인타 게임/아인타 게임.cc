#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){

        int k, n, m;
        cin >> k >> n >> m;
        
        if (n > m) swap(n, m);
        int tn = n / (k+1);
        tn %= 2;
        
        if (k == 1) tn = 0;
        
        if (n % (k+1) == 0) cout << "koosaga\n";
        else if ((n + m) % 2 == tn) cout << "cubelover\n";
        else cout << "koosaga\n";
    }
}
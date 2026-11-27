#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while(t--){
        
        ll n, p;
        cin >> n >> p;
        
        ll n1, n2;
        cin >> n1;
        
        for(int i = 0; i < n-1; i++) cin >> n2;
        
        if (n1 % (p+1) == 0) cout << "Second\n";
        else cout << "First\n";
    }
}
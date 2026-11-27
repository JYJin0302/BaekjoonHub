#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll memo[31][31];
ll comb(int n, int r) {
    if (r == 0 || n == r) return 1;

    if (memo[n][r]) return memo[n][r];
    
    memo[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
    return memo[n][r];
}

int main(){
    int t, n, m;
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        cout << comb(m, n) << endl;
    }
}
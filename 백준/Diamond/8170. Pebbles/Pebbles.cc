#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    for(int i = n-1; i >= 0; i--){
        A[i] -= A[i-1];
    }
    int res = 0;
    for(int i = n-1; i >= 0; i-= 2){
        res ^= A[i];
    }

    if (res) cout << "TAK\n";
    else cout << "NIE\n";
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

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

    for(int k = 1; k <= n/2;k ++){
        bool ok = 1;
        for(int j = 0; j < k; j++){
            if (A[j] == A[n-k+j]) {}
            else ok = 0;
        }

        if (ok){
            cout << "yes\n";
            return;
        }
    }
    cout << "no\n";
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
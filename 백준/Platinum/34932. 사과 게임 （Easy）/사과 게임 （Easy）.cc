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

    if ( n & 1){

        bool found = 0;
        for(int i = 0; i < n; i++){
            if (A[i]) continue;

            bool ok = 1;
            for(int j = 1; j <= n/2; j++){
                int i1 = (i + j) % n;
                int i2 = (i - j + n) % n;
                
                if (A[i1] != A[i2]) ok = 0;
            }
            if (ok) found=  1;
        }

        if (found) cout << "Lulu\n";
        else cout << "Terra\n";

    }
    else{
        cout << "Lulu\n";
    }
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
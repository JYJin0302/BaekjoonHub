#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    for(int i = 0 ;i < 30 && k; i++){
        ll tot = 0;
        for(auto f: A) tot += f;
        if (tot & 1){
            cout << '1';
            return;
        }
        for(auto& f : A) f >>= 1;
        k >>= 1;
    }

    cout << '0';
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

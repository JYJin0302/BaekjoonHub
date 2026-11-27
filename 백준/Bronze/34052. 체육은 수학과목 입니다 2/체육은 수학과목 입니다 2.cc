#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

void solve(){
    
    
    int tot = 0;
    for(int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        tot += x;
    }

    if (tot + 300 <= 1800) cout << "Yes\n";
    else cout << "No\n";
    

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}

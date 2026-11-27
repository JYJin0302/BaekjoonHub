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

    vector<ll> xpos(n), ypos(n);
    for(int i =0 ; i < n; i++){
        cin >> xpos[i];
        cin >> ypos[i];
    }
    sort(all(xpos));
    sort(all(ypos));

    ll ansX = 0, ansY = 0;
    ll md = ypos[n/2];
    for(auto f: ypos) {
        ansY += abs(f - md);
    }

    for(int i =0 ; i < n; i++){
        xpos[i] -= i;
    }
    sort(all(xpos));
    md = xpos[n/2];
    for(auto f : xpos) ansX  += abs(f - md);
    cout << ansX + ansY << '\n';


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

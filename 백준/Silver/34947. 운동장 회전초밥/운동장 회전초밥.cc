#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

double L[3];

void solve(){

    int n, t;
    cin >> n >> t;

    int R, D, theta, W;
    cin >> R >> D >> theta >> W;

    
    L[0] += D;
    L[1] += D;
    L[2] += D;

    for(int i =0 ;i < 3; i++){
        ld tr = R - 0.01 * W * i - 0.5 * 0.01* W;

        ld t = theta / 180.0 * acos(-1);
        ld t2 = (acos(-1) - t) / 2;

        L[i] += tr * t;
        L[i] += 2 * sin(t2) * tr;

        L[i] *= 2 * n;
    }

    cout << setprecision(20);
    cout << (L[0] - L[2]) / t << '\n';
    cout << (L[0] - L[1]) / t << '\n';
    


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
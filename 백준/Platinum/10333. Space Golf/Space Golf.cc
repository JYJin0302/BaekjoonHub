#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int d, n, b;
    cin >> d >> n >> b;
    vector<pair<int, int>> A(n);
    for(int i =0 ; i< n; i++){
        int a, b;
        cin >> a>> b;
        A[i] = mp(a, b);
    }

    double ans = 1e18;

    for(int bounce = 0; bounce <= b; bounce++){
        double T = 1.0 * d / (bounce + 1);

        //cout << "Len: " << T << '\n';
        double x = 1e18;
        bool ok = 1;
        for(auto[a,b]: A){
            int tmp = floor(a / T);
            double ta = a - floor(a / T) * T;
            double tb = b;
           // cout << ta << ' '<< tb << " => ";
            if (ta == 0){
                ok = 0; break;
            }
            double val = T * ta - ta*ta;
            val /= 2 * tb;

            //cout << "Val: " << val << '\n';
            x = min(x, val);
        }
        if (!ok) continue;

        x = sqrt(x);

        ans = min(ans, sqrt(x*x + 0.25 * (T/x) * (T/x)));

        if(2 * x * x >= T){
            ans = min(ans, sqrt(T));
        }
    }
    cout << setprecision(20);
    cout << ans << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

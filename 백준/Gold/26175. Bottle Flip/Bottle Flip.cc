#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()



void solve(){
    
    
    int h, R, da, dw;
    cin >> h >> R >> da >> dw;


    double l = 0, r= h, res = -1;
    while(r-l > 1e-7){
        double m1 = (l*2+r)/3;
        double m2 = (l + 2*r)/3;

        double ans1 = 0, ans2 = 0;
        
        double p1 = m1/2;
        double p2 = h - (h-m1)/2;

        ans1 = (p1 * dw * m1 + p2 * da * (h - m1)) / (dw*m1 + da * (h-m1));

        p1 = m2/2;
        p2 = h - (h-m2)/2;
        ans2 = (p1 * dw * m2 + p2 * da * (h - m2)) / (dw*m2 + da * (h-m2));


        //cout << l << ' '<< r << " | " << m1 << ' ' << ans1 << " | " << m2 << ' '<< ans2 << '\n';

        if(ans1 <= ans2){
            res = m1;
            r = m2;
        }
        else{
            res = m2;
            l = m1;
        }

    }

    cout << setprecision(15);
    cout <<res << '\n';
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }   
    return 0;
}


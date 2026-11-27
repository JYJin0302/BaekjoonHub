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

    vector<int> pMax(n), pMin(n);
    pMax[0] = pMin[0] = A[0];
    for(int i= 1 ;i <  n;i++){
        pMax[i] = max(pMax[i-1], A[i]);
        pMin[i] = min(pMin[i-1], A[i]);
    }

    int l , r;
    l = r = A[n-1];

    vector<double> ans(n);
    for(int i = n-1;i >= 1; i--){
        l = min(l, A[i]);
        r = max(r, A[i]);

        int tl = pMin[i-1];
        int tr = pMax[i-1];

        if (l <= tl){
            if(r <= tr) ans[i] = 0;
            else{
                ans[i] = 1.0 * (r - tr) / r;
            }
        }
        else if (r >= tr){
            ans[i] = max(1.0 * (r - tr) / r, 1.0 * (l - tl) / l);
        }
        else{
            ans[i] = 1.0 * (l - tl) / l;
        }
    }
    ans[0] = 1.0;

    cout << fixed << setprecision(15);
    for(auto f : ans) cout <<f << ' ';
    cout << '\n';


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


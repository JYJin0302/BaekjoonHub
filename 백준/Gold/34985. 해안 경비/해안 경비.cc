#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    ll W, H;
    cin >> W >> H;
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    vector<double> dif(n);
    for(int i = 1; i < n; i++){
        int x1 = A[i-1];
        int x2 = A[i];

        double h = 0;
        h = W * H;
        h /= W - x1 + x2;
        dif[i] = h;

        dif[i] += dif[i-1];
    }


    cout << setprecision(20);
    int q;
    cin >> q;
    while(q--){

        int l, r;
        cin >> l >> r;
        l--, r--;

        double totH = H * (r-l + 1);
        totH -= dif[r] - dif[l];

        cout << totH * W / 2 << '\n';

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
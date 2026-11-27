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

    sort(all(A));

    int ans = 0;
    for(int i =1; i < n; i++){
        int l = A[i-1];
        int r = A[i];

        if (gcd(l, r) == 1) {}
        else{
            bool found = 0;
            for(int v1 = l + 1; v1 < r ; v1++){
                if (gcd(l, v1) == 1 && gcd(v1, r) == 1){
                    found = 1;
                    break;
                }
            }

            if (found) {
                ans++;
                continue;
            }

            vector<int> L, R;
            for(int i = l + 1; i < r && (int)L.size() < 20; i++){
                if (gcd(l, i) == 1) L.push_back(i);
            }
            for(int i = r-1; i > l && (int)R.size() < 20; i--){
                if (gcd(r, i) == 1) R.push_back(i);
            }

            for(auto a : L){
                for(auto b : R){
                    if (a < b && gcd(a, b) == 1){
                        found = 1;
                        break;
                    }
                }
            }

            if (found){
                ans += 2;
                continue;
            }

            ans += 3;
        }

    }
    cout << ans << '\n';


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
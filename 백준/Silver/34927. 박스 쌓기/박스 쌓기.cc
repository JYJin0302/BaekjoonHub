#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    int ans = 1;
    ll s = A[0];
    for(int i =1 ; i < n; i++){
        if(A[i] >= s){
            ans++;
            s += A[i];
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
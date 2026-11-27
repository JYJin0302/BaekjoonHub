#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n, d, k;
    cin >> n >> d >> k;
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    vector<int> track(n);
    int ans = 0;
    for(int i = 0; i < d; i++){
        bool ok = 1;
        for(int j = 0; j < n;j++) {
            track[j] += A[j];
            if (track[j] > k) ok = 0;
        }

        if (!ok) {
            ans++;
            track = A;
        }
    }
    cout << ans << '\n';

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
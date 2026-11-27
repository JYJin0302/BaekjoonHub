#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

void solve(){

    ull A,B,C,n; cin>>A>>B>>C>>n;
    ull mod = 1;
    for(int i = 1; i <= 63; i+= 2){
        mod += (1ull << i);
    }

    ull ans = 0;
    if (n & 1){

        ull tn = n/2;
        ans += tn*(tn+1)/2;

        ans *= n;
        ans *= mod;
    }
    else{
        ull tn = n/2;
        ans += tn*(tn+1)/2 - 1;
        ans += tn - 1;

        ans *= n;
        ans *= mod;
    }

    vector<ull> tmp = {A, B, C};
    sort(tmp.begin(), tmp.end());

    if (tmp[0] == tmp[2]) {}
    else if (tmp[0] == tmp[1] || tmp[1] == tmp[2]) ans *= 3;
    else ans *= 6;

    cout << ans;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc=1;
    while(tc--){
        solve();
    }
}

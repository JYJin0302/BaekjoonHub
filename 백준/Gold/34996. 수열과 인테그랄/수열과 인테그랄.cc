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
     
    double ans = 0;
    for(int i = 1; i <= n - 1; i++){
        ans += i + i+1;
    }
    ans += n;

    cout << setprecision(10);
    cout << ans << '\n';
    for(int i = 1; i <= n; i++){
        cout << -i << ' ';
    }
    cout << 0 << ' ';
    for(int i = n; i >= 1; i--){
        cout << i << ' ';
    }
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
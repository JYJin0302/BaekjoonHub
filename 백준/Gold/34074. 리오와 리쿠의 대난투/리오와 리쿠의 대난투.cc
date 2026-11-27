#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair


void solve(){

    int n, m;
    cin >> n >> m;

    if (n+ m == 2){
        cout << -1 << '\n';
        return;
    }

    if (n == 1){
        cout << 10000 << '\n';
        for(int i =0 ; i < m/2; i++) cout << i +1 << ' ';
        for(int i = 0; i < m-m/2; i++) cout << 10001 + i << ' ';
        cout << '\n';
    }
    else{

        for(int i = 0; i < n-1; i++) cout << i+1 << ' ';
        cout << 100000000 << '\n';

        for(int i = 0 ; i< m;i++) cout << 10000 + i << ' ';
        cout << '\n';
    }
        
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
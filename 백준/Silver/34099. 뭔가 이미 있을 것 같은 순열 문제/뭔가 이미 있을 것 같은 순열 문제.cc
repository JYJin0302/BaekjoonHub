#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair


void solve(){
    
    int n, k;
    cin >> n >> k;

    if (k == 1){
        if (n <= 3) cout << -1 << '\n';
        else if (n == 4){
            cout << "2 4 1 3\n";
        }
        else{
            for(int i = 1;i <= n; i+= 2) cout << i << ' ';
            for(int i = 2; i <= n; i+= 2) cout << i << ' ';
            cout << '\n';
        }
    }
    else{
        for(int i = 1; i <= n ;i++) cout << i << ' ';
        cout << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
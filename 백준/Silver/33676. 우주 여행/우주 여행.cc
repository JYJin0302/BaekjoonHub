#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

void solve(){

    int n, m, k, l;
    cin >> n >> m >> k >> l;

    for(int i =0 ; i < k; i++){
        int a, b;
        cin >> a >> b;
    }

    int d = n + m - 2;
    if (d % 2 != l % 2 || l < d){
        cout << -1 << '\n';
    } 
    else{
        cout << string(n-1, 'D') << string(m-1, 'R');
        for(int i = 0; i < (l - d) / 2; i++) {
            cout << "LR";
        }
        cout << '\n';
    }
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
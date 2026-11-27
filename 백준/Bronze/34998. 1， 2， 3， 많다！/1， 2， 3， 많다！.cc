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

    int res = 0;
    for(int i = 0; i < n+1; i++){
        char c;
        cin >> c;
        if (c == '!') res += 10;
        else res += c - '0';

        if (i != n) cin >> c;
    }

    if (res <= 9) cout << res << '\n';
    else cout << "!\n";


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
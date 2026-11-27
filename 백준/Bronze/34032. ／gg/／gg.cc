#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for(auto f : s) if (f == 'O') cnt++;

    if (cnt*2 >= n){
        cout << "Yes\n";
    }
    else cout << "No\n";

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while(t--) solve();

    return 0;
}
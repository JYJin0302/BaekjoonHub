#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int cnt[30];
void solve(){
    
    string s, t;
    cin >> s >> t;

    for(auto f : s) cnt[f-'A']++;
    for(auto f : t) cnt[f-'A']--;

    for(int i =0; i < 26; i++){
        if (cnt[i] < 0){
            cout << "NEED FIX\n";
            return;
        }
    }
    cout << "OK\n";

}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
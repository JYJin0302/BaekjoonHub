#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {
 
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    vector<int> cnt(3);
    for(auto f : A){
        if (f == 1){
            if (cnt[2]) cnt[2]--;
            else cnt[1]++;
        }
        else{
            if (cnt[1]) cnt[1]--;
            else cnt[2]++;
        }
    }
    
    if(cnt[2] || cnt[1] % 3 != 0) cout << "No\n";
    else cout << "Yes\n";

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
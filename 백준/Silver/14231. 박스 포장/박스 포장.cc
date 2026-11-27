#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    vector<int> num;
    for(auto f :A){
        int ix=  lower_bound(all(num), f)- num.begin();
        if (ix == (int)num.size()) num.push_back(f);
        else num[ix] = f;
    }
    cout << (int)num.size()<< '\n';
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> A(m);
    for(int i = 0; i < m; i++){
        cin >> A[i].x;
        A[i].y = i;
    }
    sort(all(A));
    reverse(all(A));

    int tot = 0;
    vector<int> ans;
    for(auto[a,b] : A){
        if (tot + a <= n*2){
            tot += a;
            ans.push_back(b);
        }
    }
    cout << (int)ans.size() << '\n';
    for(auto f : ans) cout << f + 1 << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

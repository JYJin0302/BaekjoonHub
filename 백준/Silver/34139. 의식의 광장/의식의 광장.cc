#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int h, n;
    cin >> h >> n;

    vector<pair<int, int>> A(n);
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        A[i] = mp(b, i);
    }
    sort(all(A));
    reverse(all(A));

    vector<int> ans(n);
    int cur = n;
    for(auto[a,b] : A){
        ans[b] = cur;
        cur--;
    }

    cout << "YES\n";
    for(auto f : ans) cout << f<< ' ';
    cout << '\n';


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
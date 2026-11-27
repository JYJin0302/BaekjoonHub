#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 998244353;


void solve() {
    
    int n;
    cin >> n;

    vector<pair<int, int>> A, B;
    for(int i =0; i < n; i++){
        int a, b;
        cin >> a >> b;
        A.push_back(mp(a, b));
    }
    sort(all(A));

    B.push_back(A[0]);
    for(int i = 1; i < n;i++){
        if (B.back().x == A[i].x) {
            B.back().y = max(B.back().y, A[i].y);
        }
        else if(A[i].y <= B.back().y) {}
        else{
            B.push_back(A[i]);
        }
    }

    int ans = 1;
    int pre = B[0].y - 1;
    for(int i = 1; i < (int)B.size(); i++){
        if (B[i].x < pre && B[i].y > pre) {}
        else{
            ans++;
            pre = B[i].y - 1;
        }
    }
    cout << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
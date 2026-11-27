#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()
 
vector<int> lst[1001010];
 
void solve(){
 
    int n;
    cin >> n;
 
    vector<int> A(n);
    for(auto &i : A) cin >> i;
 
 
    vector<array<int, 3>> ans; 
    for(int i = 0; i < n; i++){
        int v = A[i];
        if(i >= 2){
            v += A[i-2];
        }
 
        if(v){
            ans.push_back({i+1, v, 3});
        }
    }
    
    cout << (int)ans.size() << '\n';
    for(auto f :ans){
        cout << f[0] << ' ' << f[1] << ' '<< f[2] << '\n';
    }
 
}
 
 
 
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
 
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

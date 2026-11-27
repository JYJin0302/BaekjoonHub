#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;


#define mp make_pair
typedef long long ll;
void solve(){

    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    vector<int> cur(n);
    for(int i =0 ; i < n;i++) cur[i] = i+1;

    vector<pair<int, int>> ans;
    for(int i = n-1; i >= 0; i--){
        int v = A[i];
        int ix = 0;
        while(ix < n && cur[ix] != v) ix++;

        for(int j = ix-1; j >= 0; j--){
            ans.push_back(mp(v, cur[j]));
        }
        for(int j = 0; j <= i; j++){
            if (cur[j] == v) continue;
            ans.push_back(mp(cur[j], v));
        }

        while(ix < i) {
            swap(cur[ix], cur[ix+1]);
            ix++;
        }   
    }

    cout << ans.size() << '\n';
    for(auto[a,b] : ans) cout << a << ' ' << b << '\n';


}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
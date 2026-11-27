#include <bits/allocator.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){   

    int n;
    cin >> n;
    vector<int> ans;

    if (n & 1){
        ans.push_back(3);
        n -= 3;
    }
    while(n){
        ans.push_back(2);
        n -= 2;
    }

    cout << ans.size() << '\n';
    for(auto f : ans) cout <<f << ' ';
    cout << '\n';


}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}
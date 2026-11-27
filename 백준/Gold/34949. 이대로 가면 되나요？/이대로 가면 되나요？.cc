#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


vector<int> pre[202020];

void solve(){

    int n;
    cin >> n;
    
    vector<int> A(n+1);
    for(int i =1; i <= n; i++) {
        cin >> A[i];
        if (i != n){
            pre[A[i]].push_back(i);
        }
    }

    vector<int> ans(n+1, -1);
    ans[n] = 0;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        auto f =q.front(); q.pop();

        for(auto d : pre[f]){
            if (ans[d] == -1){
                ans[d] = ans[f] + 1;
                q.push(d);
            }
        }
    }

    for(int i=1; i <= n; i++) cout << ans[i] << '\n';

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
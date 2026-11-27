#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[606060];

void solve(){

    int k;
    cin >> k;

    vector<int> A(k);
    for(auto& i : A) cin >> i;
    sort(all(A));

    int mn = A[0];
    int mx = A.back();
    
    if (mn != 0){
        cout << -1 << '\n';
        return;
    }

    int pre = 0;
    for(int i = 1; i < k; i++){
        int L = A[i-1];
        int R = A[i];

        int px = R;
        int cur = L + 1;
        for(int i = R-2; i >= L; i -=2){
            if (i == L) adj[cur].push_back(pre);
            else adj[cur].push_back(i);
            adj[cur].push_back(px);
            px = cur;
            cur += 2;
        }
        pre = R - 1;
    }

    int n = mx / 2;
    cout << n << '\n';
    for(int i= 1; i <= n; i++){
        int ix = i * 2 - 1;
        //cout << "ADJ : " << ix << " +> ";
        for(auto f :adj[ix]) cout << f<< ' ';
        cout << '\n';
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
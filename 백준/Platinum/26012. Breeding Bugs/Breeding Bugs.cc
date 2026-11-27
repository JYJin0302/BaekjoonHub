#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

bool isP[20001010];

vector<int> adj[777];
int L[777];
bool vis[777];
bool go(int x){
    if(vis[x]) return 0;
    vis[x] = 1;

    for(auto f : adj[x]){
        if (L[f] == -1 || go(L[f])){
            L[f] = x;
            return 1;
        }
    }
    return 0;
}

void solve(){
    
    int n;
    cin >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    sort(all(A));

    int s= 0;
    while(s < n && A[s] == 1) s++;
    if (s) s--;

    for(int i = s; i < n; i++){
        for(int j = i+1; j < n; j++){
            if (!isP[A[i] + A[j]]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
                //cout << "Edge: "<< i << ' ' << j << '\n';
            }
        }
    }

    memset(L, -1, sizeof L);
    int ans = n - s;
    int con = 0;
    for (int i = s; i < n; i++){
        if(A[i] & 1){
            memset(vis, 0, sizeof vis);
            con += go(i);
        }
    }   
    cout << ans - con << '\n';

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i= 2; i <= 20000000; i++){
        if (isP[i]) continue;
        for(int j = i*2; j <= 20000000; j += i) isP[j] = 1;   
    }

    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
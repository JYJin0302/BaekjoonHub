#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()
 
void solve() {
 
    int n;
    cin >> n;
 
    vector<int> A(n + 1);
    for(int i = 1; i <= n; i++) cin >> A[i];
 
    int cnt = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(A[j] > A[i]) cnt++;
        }
    }
 
 
    vector<pair<int, int>> ans;
    
    int cc = n;
    while(cc > 1){
 
        //cout << "Step: " << cc << '\n';
        if (A[cc] == cc){
            if (cc == 2) break;
            if (cc == 3){
                if (A[1] == 1 && A[2] == 2) break;
                ans.push_back(mp(1, 3)); swap(A[1], A[3]);
                ans.push_back(mp(1, 2)); swap(A[1], A[2]);
                ans.push_back(mp(2, 3)); swap(A[2], A[3]);
                cc -= 3;
            }
            else{
                int ni = cc - 1;
                if (A[ni] == ni){
 
                    int u = ni-2, v= ni-1;
                    ans.push_back(mp(u, ni)); swap(A[u], A[ni]);
                    ans.push_back(mp(v, cc)); swap(A[v], A[cc]);
                    
                    for(int i = 1; i < u; i++){
                        ans.push_back(mp(i, ni)); swap(A[i], A[ni]);
                        ans.push_back(mp(i, cc)); swap(A[i], A[cc]);
                    }
                    
                    ans.push_back(mp(v, ni)); swap(A[v], A[ni]);
                    ans.push_back(mp(u, cc)); swap(A[u], A[cc]);
 
                    ans.push_back(mp(ni, cc)); swap(A[ni], A[cc]);                    
 
                }
                else{
                    int ix = 1;
                    while(ix <= n && A[ix] != ni) ix++;
                    int ix2 = 1;
                    while(ix2 <= n && ix2 == ix) ix2++;
 
                   // cout << "Go three: " << ix << ' ' << ni << ' ' << cc << '\n';
                    
                    ans.push_back(mp(ix2, cc)); swap(A[ix2], A[cc]);
                    for(int i =1 ; i < ni; i++){
                        if (i != ix && i != ix2){
                            ans.push_back(mp(i, ni)); swap(A[i], A[ni]);
                            ans.push_back(mp(i, cc)); swap(A[i], A[cc]);
                        }
                    }
 
                    ans.push_back(mp(ix, cc)); swap(A[ix], A[cc]);
                    ans.push_back(mp(ix, ni)); swap(A[ix], A[ni]);
                    ans.push_back(mp(ix2, ni)); swap(A[ix2], A[ni]);
                    ans.push_back(mp(cc, ni)); swap(A[cc], A[ni]);
                }
                cc -= 2;
            }
        }
        else{
            int ix = 1;
            while(ix <= n && A[ix] != cc) ix++;
 
            for(int j = 1; j < cc; j++){
                if (j != ix) {
                    ans.push_back(mp(j, cc));
                    swap(A[j], A[cc]);
                }
            }
            ans.push_back(mp(ix, cc));
            swap(A[ix], A[cc]);
            cc--;
        }
        // for(int i =1 ; i <= n; i++) cout << A[i] << ' ';
        // cout << '\n';
    }
 
    if ((int)ans.size() != n * (n -1) /2){
        cout << 0 << '\n';
        return;
    }
 
    cout << "1\n";
    for(auto[a,b]: ans) cout << a<< ' ' << b << '\n';
 
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

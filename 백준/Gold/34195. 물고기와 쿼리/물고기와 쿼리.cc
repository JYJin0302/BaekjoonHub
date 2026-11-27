#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()
 
 
int n;
int fw[303030];
void update(int ix, int val){
    while(ix <= n){
        fw[ix] += val;
        ix += ix & -ix;
    }
}
 
int getS(int ix){
    int res = 0;
    while(ix){
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res % 2;
}
 
void solve() {
 
    cin >> n;
    string s;
    cin >> s;
 
    vector<int> A(n + 1);
    for(int i =0 ; i < n; i++){
        int v= (s[i] == '>');
        A[i+1] = v ^ (i % 2);
    }
 
    // for(auto f : A) cout <<f << ' ';
    // cout << '\n';
 
    int ans = 0;
    for(int i = 3; i <= n; i++){
        if (A[i] == A[i-1] && A[i] == A[i-2]) ans++;
    }
 
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        if ( t== 2){
            cout << ans << '\n';
        }
        else{
            int l, r;
            cin >> l >> r;
 
            vector<int> lst;
            if (r - l <= 1){
                for(int i = l; i <= r+2; i++){
                    lst.push_back(i);
                }
            }
            else{
                lst.push_back(l);lst.push_back(l+1);
                lst.push_back(r+1);lst.push_back(r+2);
            }
 
            for(auto f : lst){
                if (f <= 2 || f > n) continue;
                int v0 = getS(f) ^ A[f];
                int v1 = getS(f-1) ^ A[f-1];
                int v2 = getS(f-2) ^ A[f-2];
                if (v0 == v1 && v0 == v2) ans--;
            }
 
            update(l, 1);
            update(r+1, 1);
 
            for(auto f : lst){
                if (f <= 2 || f > n) continue;
                int v0 = getS(f) ^ A[f];
                int v1 = getS(f-1) ^ A[f-1];
                int v2 = getS(f-2) ^ A[f-2];
                if (v0 == v1 && v0 == v2) ans++;
            }
        }
    }
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

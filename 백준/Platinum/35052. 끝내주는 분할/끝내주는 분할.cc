#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n;
int fw[303030];
int fw2[303030];

void update(int ix, int val, int fw[]){
    while(ix <= n){
        fw[ix] += val;
        ix += ix & -ix;
    }
}
int getS(int ix, int fw[]){
    int res = 0;
    while(ix){
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}

void solve(){
    
    cin >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;
    vector<int> B(n);
    for(auto& i : B) cin >> i;

    int ans = 0;
    int ix = 0;
    while(ix < n){
        int nx = ix;
        while(nx < n){
            int v1 = getS(A[nx], fw);
            int v2 = getS(B[nx], fw2);
            if (v1 != v2) break;

            update(A[nx], 1, fw);
            update(B[nx], 1, fw2);
            nx++;
        }

        ans++;
        for(int j = ix; j < nx; j++){
            update(A[j], -1, fw);
            update(B[j], -1, fw2);
        }
        ix = nx;
    }
    cout << ans << '\n';


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

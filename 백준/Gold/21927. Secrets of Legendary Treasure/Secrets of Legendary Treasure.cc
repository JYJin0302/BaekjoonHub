#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()

void solve(){
    
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;

    int i0 = 0, i1 = 0;

    int cur = 1;
    while(cur <= n + m){
        int n0 = i0, n1 = i1;
        int val0 = 0, val1 = 0;
        while(n0 < n && A[n0] == 0) n0++;
        if (n0 == n) val0 = n + m + 1;
        else val0 = A[n0];
        
        while(n1 < m && B[n1] == 0) n1++;
        if (n1 == m) val1 = n + m + 2;
        else val1 = B[n1];

       // cout << "State: " << i0 << ' '<< n0 << " - " << i1 << ' '<< n1 << " - " << val0 << ' ' << val1 << endl;
        if (val0 < val1){
            while(cur < val0 && i0 < n0 && A[i0] == 0) {
                A[i0++] = cur++;
            }
            while(cur < val0 && i1 < n1 && B[i1] == 0) {
                B[i1++] = cur++;
            }
            i0++;
            cur++;
        }
        else{
            while(cur < val1 && i1 < n1 && B[i1] == 0) {
                B[i1++] = cur++;
            }
            while(cur < val1 && i0 < n0 && A[i0] == 0) {
                A[i0++] = cur++;
            }
            i1++;
            cur++;
        }
    }

    for(auto f : A) cout <<f << ' ';
    cout << '\n';
    for(auto f : B) cout <<f << ' ';
    cout << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
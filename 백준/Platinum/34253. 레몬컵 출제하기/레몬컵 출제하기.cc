#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int cnt[1 << 20];

void solve() {
 
    int n, k;
    cin >> n >> k;
    
    vector<string> A(n);
    for(auto& i : A) cin >> i;

    int z = 0;
    for(int i =0 ; i < n; i++){
        int val = 0;
        if (z){
            for(int j = 0 ;j < k; j++) if (A[i][k-1-j] == '1') val += 1 << j;
        }
        else{
            for(int j = 0 ;j < k; j++) if (A[i][j] == '1') val += 1 << j;
        }

        int L = val >> 10;
        int R = val - (L << 10);
        int tL = L, tR = R;
        bool ok = 0;
        while(tL < (1 << 10)){
            int v = (tL << 10) + tR;
            if (cnt[v]){
                ok = 1;
                break;
            }
            tL = (tL + 1) | L;
        }

        if (ok){
            cout << "WellKnown\n";
            z = 0;
        }
        else{
            cout << "AdHoc\n";
            z = 1;
        }

        tL = L;
        while(tR >= 0){
            int v = (tL << 10) + tR;
            cnt[v] = 1;

            if (tR == 0) break;
            tR = (tR - 1) & R;
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
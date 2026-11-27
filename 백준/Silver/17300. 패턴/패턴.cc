#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int nd[10][10];

void solve() {
    
    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    for(int i = 0; i < n;i++){
        for(int j = i+1; j < n; j++){
            if (A[i] == A[j]){
                cout << "NO\n";
                return;
            }
        }
    }

    nd[1][3] = nd[3][1] = 2;
    nd[4][6] = nd[6][4] = 5;
    nd[7][9] = nd[9][7] = 8;
    nd[1][7] = nd[7][1] = 4;
    nd[2][8] = nd[8][2] = 5;
    nd[3][9] = nd[9][3] = 6;

    nd[1][9] = nd[9][1] = 5;
    nd[3][7] = nd[7][3] = 5;
    

    for(int i = 1; i < n; i++){
        int a = A[i-1], b = A[i];
        if (nd[a][b] != 0){
            bool ok = 0;
            for(int j  =0; j < i-1; j++){
                if (A[j] == nd[a][b]) ok = 1;
            }

            if (!ok) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";

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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int n, m;
    cin >> n>> m;

    vector<array<int, 4>> A(n);
    for(int i =0; i < n; i++){
        cin >> A[i][0] >> A[i][1] >> A[i][2] >> A[i][3];
    }

    int ans = 0;

    bool ok = 1;
    while(m--){
        int x, y;
        cin >> x>> y;

        if (!ok){
            ok = 1;
            continue;
        }

        pair<int, int> tar = mp(-1, -1);
        for(int i = 0 ;i < n; i++){
            int dx = A[i][0] - x;
            int dy = A[i][1] - y;
            if (dx * dx + dy * dy <= A[i][2] * A[i][2]){
                tar = max(tar, mp(A[i][3], i));
            }
        }
        if (tar.x == -1){
            ok = 0;

        }
        else if (tar.y == 0){
            ans++;
        }
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
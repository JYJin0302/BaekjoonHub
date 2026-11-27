#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){

    int n;
    cin >> n;

    vector<array<int, 4>> A(n);
    for(int i =0 ; i < n; i++){
        cin >> A[i][1] >> A[i][2] >> A[i][0];
        A[i][3] = i;
    }
    sort(all(A));
    reverse(all(A));

    vector<bool> used(n);
    for(int i = 0; i < n; i++){
        bool ok = 1;
        int cx = A[i][1], cy = A[i][2];

        int xl = cx - A[i][0], xr = cx + A[i][0];
        int yl = cy - A[i][0], yr = cy + A[i][0];
        for(int j =0; j < i ;j++){
            if (!used[j]) continue;

            int cx2 = A[j][1], cy2 = A[j][2];


            if ((xr <= cx2 - A[j][0] || cx2 + A[j][0] <= xl) || (yr <= cy2 - A[j][0] || cy2 + A[j][0] <= yl)){}
            else{
                ok = 0;
                break;
            }

        }
        if (ok) used[i] = 1;
    }

    vector<int> ans;
    for(int i =0 ; i< n;i++) if( used[i]) ans.push_back(A[i][3]+1);
    sort(all(ans));

    cout << (int)ans.size() << '\n';
    for(auto f : ans) cout << f<< '\n';




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

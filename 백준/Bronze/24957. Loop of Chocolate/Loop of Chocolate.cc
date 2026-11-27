#include <bits/stdc++.h>
using namespace std;
using ld = long double;

#define all(x) x.begin(), x.end()
typedef long long ll;
const ld PI = acos(-1);

void solve(){
    
    int n, r;
    cin >> n >> r;

    vector<array<int, 3>> A;
    for(int i =0 ; i < n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        A.push_back({x, y, z});
    }

    ld ans = 0;
    ans = 1.0 * 4 * PI * r * r * r / 3;
    ans *= n;
    for(int i =0 ; i < n; i++){
        for(int j = i + 1; j < n; j++){

            ll d2 = (A[i][0] - A[j][0]) * (A[i][0] - A[j][0]);
            d2 += (A[i][1] - A[j][1]) * (A[i][1] - A[j][1]);
            d2 += (A[i][2] - A[j][2]) * (A[i][2] - A[j][2]);

            if (d2 <= 4 * r* r){
                // intersect

                ld D = sqrtl(d2);
                ld v1 = 2.0 * PI * (r - D /2)*(r - D /2)*(2*r + D / 2) / 3;
                ans -= v1;
            }

        }
    }

    cout << setprecision(20);
    cout << ans << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
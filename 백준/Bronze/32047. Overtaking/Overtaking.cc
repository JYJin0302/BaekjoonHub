#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    int n;
    cin >> n;
    while(n){
        vector<int> A(n);
        for(auto& i : A) cin >> i;

        vector<int> B(n);
        for(auto& i : B) cin >> i;

        int ans = 0;
        int da = 0, db = 0;
        int state = 0;
        for(int i =0 ; i < n;i++){
            int na = da + A[i];
            int nb = db + B[i];

            if (state == 1 && na > nb) ans++;
            else if (state == -1 && na < nb) ans++;

            if (na < nb) state = 1;
            else if (na > nb) state = -1;
            da = na;
            db = nb;
        }
        cout << ans << '\n';
        cin >> n;
    }
    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}
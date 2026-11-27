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

    vector<ll> A(n);
    for(auto& i : A) cin >> i;

    for(int i = 1; i < n;i++){
        if (A[i-1] >= A[i]){
            cout << 0 << '\n';
            return;
        }
    }
    cout << 1<< '\n';
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
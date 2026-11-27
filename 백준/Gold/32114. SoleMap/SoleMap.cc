#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve(){

    int n, m;cin >> n >>  m;

    vector<ll> A(n + 10), B(n+10);
    for(int i = 0; i < n -1; i++) cin >> A[i];
    while(m--){
        int a, b, c;
        cin >> a >> b >> c;
        B[a-1] += c;
        B[b - 1] -= c;
    }

    for(int i = 1; i < n; i++) B[i] += B[i-1];

    for(int i = 0; i < n-1; i++){
        ll tot = B[i];
        ll w = A[i];

        ll d = tot / w;
        ll r = tot % w;

        ll res=  0;
        res += (w - r) * (d*d);
        res += r * (d+1)*(d+1);

        cout << res << '\n';

    }


}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
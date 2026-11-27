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
    vector<ll> A(n*2), B(n*2);
    for(int i = 0; i < n ;i++) {
        cin >> A[i];
        A[i+n] = A[i];
    }
    for(int i =0 ; i < n;i++) {
        cin >> B[i];
        B[i+n] = B[i];
    }
    for(int i = 1; i < n*2; i++){
        B[i] += B[i-1];
    }

    ll offset = 0;
    ll ans = 1e15;

    set<pair<ll, ll>> st;
    for(int i = 0; i < n; i++){
        st.insert(mp((i ? B[i-1] : 0) - A[i], i));

    }

    for(int i =0 ; i < n ;i++){

        // get ans
        while(!st.empty() && (*st.begin()).y < i){
            st.erase(st.begin());
        }

        ll minV = (*st.begin()).x;
        ans = min(ans, -minV + offset);

        //cout << "res: " << i << " | " << -minV << " + " << offset << '\n';
        offset = B[i];

        // update
        st.insert(mp(B[i+n-1]- A[i+n], i+n));
    }

    cout << ans << '\n';
    

    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
   // cin >> t;
    while(t--) {
       // cout << "Go: " << endl;
        solve();
        //cout << endl;
    }

    return 0;
}
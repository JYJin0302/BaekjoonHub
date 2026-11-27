#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    ll n;
    cin >> n;
    vector<int> A(n), B(n);
    for(auto& i : A) cin >> i;
    for(auto& i : B) cin >> i;

    vector<int> nA(n), nB(n);
    for(int i = 1 ; i < n ;i++){
        nA[i] = max(A[i], i > 1 ? nA[i-1] : 0);
        nB[i] = max(B[i], i > 1 ? nB[i-1] : 0);
    }

    ll i1 = n-1, i2 = n-1;

    map<ll, ll> cnt;

    while(1){
        int mx = max(nA[i1], nB[i2]);

        ll ni1 = i1, ni2 = i2;
        while(ni1 && nA[ni1] == mx) ni1--;
        while(ni2 && nB[ni2] == mx) ni2--;

        ll totCnt = i1 * i2 - ni1 * ni2;
        cnt[mx] += totCnt;
       // cout << "Got: " << mx << " | " << totCnt << '\n';

        i1 = ni1;
        i2 = ni2;

        if(i1 == 0 || i2 == 0) break;
    }

    for(auto f : A) cnt[f]++;
    for(auto f : B) cnt[f]++;
    cnt[A[0]]--;

    ll mxCnt = -1, mxVal = 0;
    for(auto[a,b] : cnt){
        if (b >= mxCnt){
            mxCnt = b;
            mxVal = a;
        }
        else if (b == mxCnt){
            mxVal = max(mxVal, a);
        }
    }
    
    cout << mxVal << ' ' << mxCnt << '\n';
    
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
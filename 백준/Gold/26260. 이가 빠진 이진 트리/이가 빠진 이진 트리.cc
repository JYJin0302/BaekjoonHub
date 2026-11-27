#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int A[202020];
void go(int l, int r){
    if (l == r) {
        cout << A[l] << ' ';
        return;
    }

    int md = (l+r)>>1;
    go(l, md-1);
    go(md+1, r);
    cout << A[md] << ' ';

}

void solve(){
 
    int n;
    cin >> n;

    int ix = 0;
    for(int i = 0; i < n ;i++){
        cin >> A[i];
        if (A[i] == -1){
            ix= i;
        }
    }
    cin >> A[ix];
    sort(A, A+n);

    go(0, n-1);    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    int t = 1;
   // cin >> t;
    for(int i =0 ;i < t;i ++){
        solve();
    }


    return 0;
}
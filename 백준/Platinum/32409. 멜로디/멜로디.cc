#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve(){
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(auto& i : A) cin >> i;

    for(auto& i : A) i--;

    vector<int> L(n);
    L[0] = A[0];
    for(int i =1; i < n;i++){
        L[i] = A[i] - L[i-1];
        if (L[i] < 0){
            for(int j = i; j < n; j++) L[j] = -1;
            break;
        }
    }

    for(int i = 0; i < n-1; i++){
        A[i]--;
    }
    vector<int> R(n);
    R[n-1] = A[n-1];
    for(int i = n-2;i >=0 ; i--){
        R[i] = A[i] - R[i+1];
        if (R[i] < 0){
            for(int j = i; j >= 0; j--) R[j] = -1;
            break;
        }
    }

    if(L[n-1] == 0){
        cout << "YES\n";
        return;
    }

    for(int i =0 ; i < n - 1; i++){
        int val1=  0;
        if (i) val1 = L[i-1];
        int val2 = R[i];

        if (val1 < 0 || val2 < 0) continue;
        if (val1 == val2){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";

}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
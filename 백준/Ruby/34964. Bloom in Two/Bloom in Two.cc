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

    vector<int> A(n);
    for(auto& i : A) cin >> i;

    cout << "YES\n";
    int l = 1, r = n;
    for(int i =0 ; i < n; i++){
        if (A[i] == l) {
            cout << 'E';
            l++;
        }
        else{
            cout << 'C';
            r--;
        }
    }
    cout << '\n';


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

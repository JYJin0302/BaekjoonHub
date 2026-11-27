#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    int k ,c, p;
    cin >> k >> c>> p;
    if (k == 0){
        if (c + p == 1) cout << "N\n";
        else cout << "Y\n";
    }
    else if (k == 1){
        if (p >= 2 || c >= 1) cout << "Y\n";
        else cout << "N\n";
    }
    else if (k == 2){
        if (c+p >= 2) cout << "Y\n";
        else cout << "N\n";
    }
    else{
        if (c+p>=2) cout << "Y\n";
        else cout << "N\n";
    }


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }   
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


string ans[202020];
void solve(){
    
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    vector<int> L, R, tmp;
    for(int i = 0 ; i < n; i++){
        if (s[i] == 'W') {
            tmp.push_back(i);
        }
    }
    if (int(tmp.size()) & 1){
        cout << "NO\n";
        return;
    }

    for(int i =0 ; i< int(tmp.size()); i++){
        if ( i < int(tmp.size()) / 2) L.push_back(tmp[i]);
        else R.push_back(tmp[i]);
    }


    int nd = n - 2 * int(L.size());
    
    int cnt = 0;
    for(int i= 0; i < n; i++){
        if (s[i] == 'R') L.push_back(i);
    }
    
    for(int i = n;i < n*2; i++){
        if(s[i] == 'W') R.push_back(i), cnt++;
        else {
           if (cnt == nd) {
              if (int(L.size()) <= int(R.size())) L.push_back(i);
              else R.push_back(i);
           }
           else L.push_back(i);
        }

    }

    sort(all(L));
    sort(all(R));

    // for(auto f :L ) cout << f<< ' ';
    // cout << '\n';
    // for(auto f : R) cout << f << ' ';
    // cout << '\n';

    if(int(L.size()) != int(R.size())){
        cout << "NO\n";
        return;
    }
    string ts = s;
    for(int i = 0 ; i< n ;i++) swap(ts[L[i]], ts[R[i]]);
    for(int i =0 ; i <  n;i++) if (ts[i] == 'R') {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t = 1;
    cin >> t;
    while(t--) solve();

    return 0;
}
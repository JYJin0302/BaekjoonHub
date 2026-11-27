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
    string s;
    cin >> s;

    string ts = "PAUL";
    int ix = 0;
    vector<int> A;

    int pre = -1;
    for(int i = 0; i < n && ix < 4; i++){
        if (s[i] == ts[ix]) {
            if ((i - pre) & 1) {}
            else {
                cout << "NO\n";
                return;
            }

            A.push_back(i);
            pre = i;
            ix++;
        }
    }

    if (ix != 4 || (n - pre) % 2 == 0){
        cout << "NO\n";
    }
    else cout << "YES\n";



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
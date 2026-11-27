#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    
    int n, t;
    cin >> n >> t;

    string s;
    cin >> s;

    vector<bool> res(n);
    vector<pair<int, int>> A;
    int ix = 0;
    while(ix < n){
        int nx = ix + 1;
        while(nx < n && s[nx] != s[nx-1]) nx++;
        A.push_back(mp(ix + 1, nx - 1));
        ix = nx;
    }

    for(auto[a,b] : A){
        if(a > b) continue;
        int len = b - a + 1;
        int tx = min(t, len / 2);
        
        //cout << a << ' ' << b<< " => ";
        a += tx, b -= tx;
        //cout << a << ' ' << b<< '\n';
        if (a <= b) {
            for(int j = a; j <= b; j++) res[j] = 1;
        }
    }

    char cur = s[0];
    for(int i =0 ;i < n; i++){
        if (res[i]) cur = char('A' + 'B' - cur);
        cout << cur;
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
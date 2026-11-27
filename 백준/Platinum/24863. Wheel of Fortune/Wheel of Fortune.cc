#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
const int p = 998244353;
ll base[1001010];
int ss[101010];
ll val[101010][26];

vector<string> A;
bool goSolve(vector<int> iLst, int used = 0){
    int com = (1 << 26) - 1 - used;

    // cout << "Go solve:" ;
    // for(auto f : iLst) cout <<f << ' ';
    // cout << " | ";
    // for(int j =0 ;j <26;j ++){
    //     if(used & (1 << j)) cout << 1;
    //     else cout << 0;
    // }
    // cout << '\n';

    if ((int)iLst.size() <= 1) return 1;

    for(auto i : iLst){
        com &= ss[i];
    }

    // cout << "COM : ";
    // for(int j = 0; j < 26; j++){
    //     if (com & (1 << j)) cout << 1;
    //     else cout << 0;
    // }
    // cout << '\n';

    if(com == 0) return 0;

    vector<pair<int, int>> ret;
    for(auto i : iLst){
        ll tmp = 0;
        for(int j =0 ;j < 26; j++){
            if (com & (1 << j)){
                tmp += val[i][j];
                tmp %= mod;
            }
        }
        ret.push_back(mp(tmp, i));

        //cout << "CAl: " << tmp << ' ' << i << '\n';
    }

    sort(all(ret));

    int ix = 0;
    while(ix < (int)ret.size()){
        vector<int> tmp;
        int nx= ix;
        while(nx < (int)ret.size() && ret[nx].x == ret[ix].x){
            tmp.push_back(ret[nx].y);
            nx++;
        }

        if (nx > ix + 1 && !goSolve(tmp, used | com)) return 0;
        ix = nx;
    }

    return 1;
}


void solve(){
    
    int l, n;
    cin >> l >> n;

    A = vector<string> (n);
    for(auto& i : A) cin >> i;

    base[0] = 1;
    for(int i = 1; i <= l; i++){
        base[i] = base[i-1] * p % mod;
    }

    for(int i = 0; i < n; i++){
        for(int j =0; j < l; j++){
            int ix = A[i][j] - 'a';
            val[i][ix] += base[j] * (ix + 1) % mod;
            val[i][ix] %= mod;
            ss[i] |= 1 << ix;
        }
    }

    vector<int> tmp;
    for(int i =0 ;i < n; i++) tmp.push_back(i);
    if (goSolve(tmp, 0)) cout << "YES\n";
    else cout << "NO\n";

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


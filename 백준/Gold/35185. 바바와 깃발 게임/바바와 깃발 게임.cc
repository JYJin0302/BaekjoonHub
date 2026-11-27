#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

void solve(){
    
    int n, l;
    cin >> n >> l;

    string s;
    cin >> s;

    map<int, int> cnt;
    cnt[0] = 1;
    int pos = 0;
    int L = 0, R = 0;
    for(auto f :s){
        if (f == 'L') {
            pos--;
            L= min(L, pos);
        }
        else {
            pos++;
            R = max(R, pos);
        }
        cnt[pos]++;
    }

    if (R - L + 1 > n || cnt[pos] != 1){
        cout << "DEFEAT\n";
    }
    else{
        cout <<"WIN\n";
        if (pos == L){
            cout << -L + 1 << ' ' << 1 << '\n';
        }
        else{
            cout << n - R << ' ' << n << '\n';
        }
    }




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
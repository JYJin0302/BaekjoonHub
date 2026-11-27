
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mp make_pair

void solve(){

    int n;
    cin >> n;

    vector<pair<int, int>> L, R;

    int l = 1, r = 1000;
    for(int i = 0; i < 140; i+= 7){
        L.push_back(mp(l, r));
        L.push_back(mp(l, r));
        L.push_back(mp(l+1, r-1));
        R.push_back(mp(l+1, r));
        R.push_back(mp(l+1, r));
        R.push_back(mp(l+1, r));

        L.push_back(mp(l+2, r-2));
        R.push_back(mp(l+2, r-1));

        L.push_back(mp(l+3, r-3));
        L.push_back(mp(l+3, r-3));
        L.push_back(mp(l+3, r-3));
        R.push_back(mp(l+3, r-2));
        R.push_back(mp(l+3, r-3));
        R.push_back(mp(l+3, r-3));

        l += 4;
        r -= 4;
    }

    for(int i = 140; i < n; i++) {
        L.push_back(mp(l, r));
        R.push_back(mp(l, r));
    }

    for(auto f : L) cout << f.first << ' ' <<f.second <<'\n';
    cout << '\n';
    for(auto f : R) cout << f.first << ' ' <<f.second <<'\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

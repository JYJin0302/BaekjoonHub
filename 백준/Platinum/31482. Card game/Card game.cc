#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair

void solve(){
    
    int n;
    cin >> n;
    map<char, int> cdx;
    cdx['C'] = 4;
    cdx['S'] = 0;
    cdx['W'] = 1;
    cdx['E'] = 2;
    cdx['R'] = 3;

    vector<pair<int, int>> A;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        char c = s[0];
        int v = stoi(s.substr(1, 10));
        A.push_back(mp(cdx[c], v));
    }

    int ans = 0;
    vector<int> ord(5);
    for(int i = 0; i < 5; i++){
        ord[i] = i;
    }
    do{
        vector<pair<int, int>> res;
        for(auto[a,b] : A){
            a = ord[a];
            int ix = lower_bound(res.begin(), res.end(), mp(a, b)) -res.begin();
            if (ix == res.size()) res.push_back(mp(a, b));
            else res[ix] = mp(a, b);
        }
        ans = max(ans,(int)res.size());

    }while(next_permutation(ord.begin(), ord.begin() + 4));
    cout << n-ans;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
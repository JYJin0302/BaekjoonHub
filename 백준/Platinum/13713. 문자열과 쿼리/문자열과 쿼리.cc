#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    
    string s;
    cin >> s;

    int n = s.size();
    reverse(all(s));

    vector<int> Z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++){
        if (i <= r) Z[i] = min(r - i + 1, Z[i-l]);
        while(i + Z[i] < n && s[i+Z[i]] == s[Z[i]]) Z[i]++;
        if(i + Z[i] - 1 > r){
            l = i, r = i + Z[i] - 1;
        }
    }
    Z[0] = n;

    int m;
    cin >> m;

    while(m--){
        int ix;
        cin >> ix;
        cout << Z[n-ix] << '\n';
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

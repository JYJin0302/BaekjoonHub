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

    vector<int> cntL(n), cntO(n);
    for(int i =0 ; i < n;i++){
        if (s[i] == 'L') cntL[i]++;
        else cntO[i]++;

        if (i) {
            cntL[i] += cntL[i-1];
            cntO[i] += cntO[i-1];
        }
    }
    for(int i = 0 ;i < n-1; i++){
        if (cntL[i] != cntL[n-1] - cntL[i] && \
        cntO[i] != cntO[n-1] - cntO[i]){
            cout << i +1  << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}
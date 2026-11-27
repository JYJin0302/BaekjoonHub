

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans = 10;
void bt(string curr, int cnt = 0, int f = 1){
    bool ok= 1;
    for(auto f : curr) if(f == '0') ok = 0;
    if (ok){
        ans = min(ans, cnt);
        return;
    }
    if(cnt == 6) return;

    for(int k = f; k <= min(20, (int)curr.size()-1); k++){
        string ns = curr;
        for(int i = curr.size()-1; i >= k; i--){
            if (ns[i-k] == '1') ns[i] = '1';
        }
        if (ns != curr) bt(ns, cnt+1, k);
    }
}

void solve(){

    string s;
    cin >> s;

    if (s[0] == '0'){
        cout << -1;
        return;
    }

    int n = s.size();
    bt(s);

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    int tc = 1;
//    cin>>tc;
    while(tc--){
        solve();
    }
    return 0;
}

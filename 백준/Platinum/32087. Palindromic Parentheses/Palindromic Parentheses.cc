#include <bits/stdc++.h>
using namespace std;

void solve(){
    
    int n, k;
    cin >> n >> k;

    if (k < n/2 || k == n){
        cout << -1 << '\n';
        return;
    }
    if( k== n/2){
        cout << string(n/2, '(') << string(n/2, ')') << '\n';
        return;
    }

    string ans(n, ')');

    int l = 0, r = k - 1;
    if (k & 1){
        int cnt = 0;
        while(cnt < n - k){
            ans[l++] = '(';
            ans[r--] = '(';
            cnt += 2;
        }

        char c = ')';
        for(int i = l; i <= r; i++){
            ans[i] = c;
            c = char('(' + ')' - c);
        }
    }
    else{
        int cnt = 0;
        while(cnt < n - k){
            ans[l++] = '(';
            ans[r--] = '(';
            cnt += 2;
        }

        char c = ')';
        while(l < r){
            ans[l++] = c;
            ans[r--] = c;
            c = char('(' + ')' - c);
        }
    }

    bool ok = 1;
    int val = 0;
    for(auto f  : ans){
        if (f == '(') val++;
        else val--;
        if (val < 0) ok = 0;
    }
    if (val != 0) ok = 0;

    if(!ok){
        ans = '(' + ans.substr(0, n-1);
    }

    cout << ans << '\n';

}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
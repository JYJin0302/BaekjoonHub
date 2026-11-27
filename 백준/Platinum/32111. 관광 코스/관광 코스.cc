#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ix= 0 ;
    while(ix < n && s[ix] == 'X') ix++;

    if (ix == n){
        cout << "YES\n";
        cout << string(n, '-') << '\n';
        return;
    }

    string ans(n*2, '?');
    ans[ix] = '+';

    int lim = ix + n;
    while(ix < lim){
        int nx = ix + 1;
        int len = 0;
        while(nx < lim && s[nx%n] == 'X') nx++, len++;

        ans[ix] = '+';
        for(int i = 0; i < len; i++){
            if (i < len / 2) ans[(ix + i + 1) % n] = '+';
            else ans[(ix + i + 1) % n] = '-';
        }
        ix = nx;
    }

    vector<int> val(n), mval(n), sufm(n);
    for(int i= 0; i < n; i++){
        if (ans[i] == '+') val[i] = 1;
        else val[i] = -1;

        
        if (i) {
            val[i] += val[i-1];
        }

        mval[i] = val[i];
        if (i) mval[i] = min(mval[i], mval[i-1]);
    }

    for(int i= n-1; i >=0 ; i--){
        sufm[i] = val[i];
        if(i != n-1) sufm[i] = min(sufm[i], sufm[i+1]);
    }

   // for(int i = 0; i < n; i++) cout << ans[i];
   // cout << '\n';
    for(int i = 0; i < n; i++){
        if (s[i] == 'X'){
            
            if(ans[i] == '-' || sufm[i] < val[i] - 1) {}
            else{
                int tt = val[n-1] - (i ? val[i-1] : 0);
                if(i && mval[i-1] < -tt) {}
                else{
                    cout << "NO\n";
                    return;
                }
            }

        }
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
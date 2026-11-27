#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const ll INF = 4e18;
ll dp[70][70];
ll getDp(int n, int r){
    // 현재 offset : n, r 개 채우는 경우의 수
    if (n + r > 63) return 0;
    if (dp[n][r] != -1) return dp[n][r];

    if(r == 0){
        if (n == 0){
            return dp[n][r] = 1;
        }
        return dp[n][r] = 0;
    }

    ll ret = 0;
    if (n) ret += getDp(n-1, r-1);
    ret += getDp(n+1, r-1);
    ret = min(ret, INF);
    return dp[n][r] = ret;
}

void solve(){
    memset(dp, -1, sizeof dp);

    string s;
    cin >> s;

    ll k;
    cin >> k;

    int n = (int)s.size();

    vector<int> pos;
    for(int i = 1; i < n; i++){
        if (s[i] == '-' && s[i-1] == '-'){
            pos.push_back(i);
        }
    }

    string base ;
    for(int i =0; i < n; i++){
        if (i && s[i] == s[i-1] && s[i] == '-') base += '_';
        base += s[i];
    }

    vector<string> tab;
    int tn = (int)base.size();

    int cnt = (int)pos.size();
    if (cnt & 1){
        cnt++;
        for(int i =0 ; i <= tn; i++){
            string tmp = base.substr(0, i) + '_' + base.substr(i);
            tab.push_back(tmp);
        }
        sort(all(tab));
        tab.erase(unique(all(tab)), tab.end());
    }
    else tab.push_back(base);

    tn = (int)tab[0].size();
    // cout << "TABle\n";
    // for(auto f  : tab){
    //     cout <<f << '\n';
    // }

    string ans(tn, '.');
    int curOff = 0;
    int bCnt = cnt;

    int tabS = (int)tab.size();
    vector<bool> able(tabS, 1), t_able(tabS);
    
    for(int i = 0; i< tn; i++){
        char nxt = '?';
        for(auto c : {'+', '-', '{', '}'}){
            ll cnt = 0;
            for(int j = 0; j < tabS; j++){
                if(!able[j]) continue;

                ll cc = 0;
                if (c == '+' || c == '-'){
                    if (tab[j][i] == c) {
                        // match
                        cc = getDp(curOff, bCnt);
                    }
                }
                else if (c == '{'){
                    if (tab[j][i] == '_'){
                        // match
                        cc = getDp(curOff + 1, bCnt - 1);
                    }
                }
                else{
                    if (tab[j][i] == '_' && curOff > 0){
                        // match
                        cc = getDp(curOff - 1, bCnt - 1);
                    }

                }
                cnt += cc;
                cnt = min(cnt, INF);
            }

            if (cnt >= k){
                // use this
                nxt = c;
                t_able = vector<bool> (tabS);
                for(int j =0 ; j< tabS; j++){
                    if(!able[j]) continue;
                    if (c == '+' || c == '-'){
                        if (tab[j][i] == c) {
                            // match
                            t_able[j] = 1;
                        }
                    }
                    else if (c == '{'){
                        if (tab[j][i] == '_'){
                            // match
                            t_able[j] = 1;
                        }
                    }
                    else{
                        if (tab[j][i] == '_' && curOff > 0){
                            // match
                            t_able[j] = 1;
                        }
                    }
                }
                swap(able, t_able);
                break;
            }
            else{
                k -= cnt;
            }
        }

        if (nxt == '?'){
            cout << "Overflow\n";
            return;
        }

        if (nxt == '{') {
            curOff++;
            bCnt--;
        }
        else if (nxt == '}'){
            curOff--;
            bCnt--;
        }
        ans[i] = nxt;
    }

    cout << ans << '\n';
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



#include <bits/stdc++.h>
#define ll long long
using namespace std;

map<string, int> sdx;
int n, m, ansi;
vector<int> adj[505];
vector<int> dp[505];
string val[505], target;

void dfs(int v){

    if (dp[v][0] != -1){
        ansi += dp[v][ansi];
        return;
    }

    if(adj[v].size() == 0){
        // leaf

        dp[v][m] = 0;
        int sz = val[v].size();
        for(int i = 0; i < m; i++){
            int res = 0;
            for(int j =0;j < sz && i + res < m; j++){
                if (target[i+res] == val[v][j]) res++;
            }
            dp[v][i] = res;
        }
        ansi += dp[v][ansi];
        return;
    }
    int a = adj[v][0], b=  adj[v][1];
    dfs(a);
    dfs(b);

    dp[v][m] = 0;
    for(int i = 0; i < m; i++){
        dp[v][i] = dp[a][i] + dp[b][i + dp[a][i]];
    }
}

void solve(){


    cin >> n;
    cin.ignore();

    sdx.clear();
    target = "";
    for(int i = 0; i <= n+1; i++) {
            adj[i].clear();
            dp[i].clear();
            val[i] = "";
    }
    int cnt = 0;
    for(int i = 0; i <n; i++){
        string s;
        getline(cin, s);

        vector<string> tdx;
        string tmp= "";
        for(int j = 0; j <= s.size(); j++){
            if (j < s.size() && isalpha(s[j])) tmp += s[j];
            else{
                if (tmp != ""){
                    tdx.push_back(tmp);
                }
                tmp = "";
            }
        }

         if (tdx.size() == 3){
            int a, b, c;
            for(auto k : tdx){
                if(sdx[k] == 0) sdx[k] = ++cnt;
            }
            a = sdx[tdx[0]];
            b = sdx[tdx[1]];
            c = sdx[tdx[2]];
            adj[a].push_back(b);
            adj[a].push_back(c);

            //cout << "ADJ:"<<a <<' ' <<b <<' ' <<c <<'\n';
         }
         else{
            if (sdx[tdx[0]] == 0) sdx[tdx[0]] = ++cnt;
            val[sdx[tdx[0]]] = tdx[1];
            //cout << "Res: "<< sdx[tdx[0]] <<' ' << tdx[1] <<'\n';
         }
    }

    string s;
    cin >>s;

    int si = sdx[s];
    cin >> target;
    m = target.size();

    for(int i= 0; i <= cnt;i ++){
        dp[i] = vector<int>(m+10, -1);
    }

    ansi = 0;
    dfs(si);

    if (ansi == m)cout <<"YES\n";
    else cout <<"NO\n";

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >>t;
    while(t--){
        solve();
    }

}


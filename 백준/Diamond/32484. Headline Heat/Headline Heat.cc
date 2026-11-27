#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int encode(char c){
    if (isalpha(c)) return c - 'a';
    return 26;
}

vector<int> adj[101010];


string U[101010];
ll H[101010];
ll Nval[101010];

const int mod = 1e9 + 7;
const int p = 1000003;

struct Node{
    int ch[27];
    int fail;
    ll S;

    Node(){
        memset(ch, -1, sizeof ch);
        S = 0;
        fail = 0;
    }

} aho[2002020];

int aho_size = 0;
void insert(int cur, int ix, int pos){
    //cout << "St: " << cur << ' '<< ix << ' '<< pos << '\n';
    if (pos == (int)U[ix].size()){
        // end
        (aho[cur].S += Nval[ix]) %= mod;
        return;
    }

    int nxt = encode(U[ix][pos]);
    if (aho[cur].ch[nxt] == -1) {
        aho[cur].ch[nxt] = ++aho_size;
    }

    insert(aho[cur].ch[nxt], ix, pos+1);
}

void setFail(){
    
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int i = 0; i < 27; i ++){
            if(aho[cur].ch[i] != -1){
                int nxt = aho[cur].ch[i];
                // set fail
                int ret = aho[cur].fail;
                while(ret && aho[ret].ch[i] == -1) ret = aho[ret].fail;

                if(cur  && aho[ret].ch[i] != -1) ret = aho[ret].ch[i];
                aho[nxt].fail = ret;
                (aho[nxt].S += aho[ret].S) %= mod;
                //cout << "SEt :" << nxt << ' ' << ret << '\n';
                q.push(nxt);
            }
        }
    }
}



void solve(){
    
    int n, m, k;
    cin >> n >> m >> k;

    cin.ignore();
    for(int i =0 ;i <  n;i++){
        string s;
        getline(cin, s);
        U[i] = s;
    }

    for(int i = 1; i <= m; i++){
        int a, b;
        cin >> a>> b;
        if(a > b) {
            adj[a].push_back(-i);
            adj[b].push_back(i);
        }
        else{
            adj[a].push_back(i);
            adj[b].push_back(-i);
        }
    }
    cin.ignore();


    // setup
    H[0] = 1;
    for(int i = 1; i <= m; i++){
        H[i] = H[i-1] * p % mod;
    }
    for(int i = 1; i<= n; i++){
        ll val = 0;
        for(auto f : adj[i]){
            if (f > 0) val = (val + H[f]) % mod;
            else val = (val + mod - H[-f]) % mod;
        }
        Nval[i-1] = val;
    }

    for(int i = 0; i < n; i++){
        insert(0, i, 0);
    }
    setFail();

    for(int i =0 ;i < k; i++){
        string s;
        getline(cin, s);

        ll tot = 0;
        int cur = 0;
        for(int j = 0; j < (int)s.size(); j++){
            int nxt = encode(s[j]);
            while(cur && aho[cur].ch[nxt] == -1){
                cur = aho[cur].fail;
            }

            if (aho[cur].ch[nxt] != -1){
                cur = aho[cur].ch[nxt];
                tot = (tot + aho[cur].S) % mod;
            }

            //cout << "Current: " << cur << ' '<< aho[cur].S << ' ' << tot << endl;
        }

        if (tot == 0) cout << "yes\n";
        else cout << "no\n";
        
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

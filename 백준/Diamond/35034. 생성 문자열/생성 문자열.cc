#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n, Q;
string S[30];
ll len[30];
int off[30];
int encode(int s, int ix){
    return off[s] + ix;
}
pair<int, int> decode(int ix){
    int res = lower_bound(off, off + n, ix + 1) - off - 1;
    return mp(res, ix - off[res]);
}

vector<ll> tLen[33];

vector<int> adj[30];
pair<ll, ll> jmp[33];

pair<ll, ll> spt[60][33];

int topo[30];

void solve(){

    cin >> n >> Q;

    for(int i = 0 ; i < n; i++) {
        cin >> S[i];
    }

    for(int i =0 ; i < n; i++){
        int tn = (int)S[i].size();
        off[i + 1] = tn + off[i];
    }

    for(int i =0 ;i < n; i++){
        for(auto f : S[i]){
            if (f >= 'A' && f <= 'Z'){
                int ix = f- 'A';
                topo[i]++;
                adj[ix].push_back(i);
            }
            else len[i]++;
        }
    }

    // finite 처리
    queue<int> q;
    for(int i =0 ;i < n; i++){
        if (topo[i] == 0) q.push(i);
    }
    while(!q.empty()){
        int a = q.front(); q.pop();
       // cout << "Done: " << a << ' ' << len[a] << '\n';
        for(auto f: adj[a]){
            topo[f]--;
            len[f] += len[a];
            len[f] = min(len[f], (ll)4e18);
            if (topo[f] == 0)q.push(f);
        }
    }

    for(int i = 0; i < n; i++){
        ll tLen = 0;
        jmp[i] = mp(-1, -1);
        if (topo[i] == 0) continue;

        int cc = 0;
        for(auto f: S[i]){
            cc++;
            if (f >= 'A' && f <= 'Z'){
                int ix = f- 'A';
                if (topo[ix] == 0){
                    tLen = min(ll(4e18), tLen + len[ix]);
                }
                else{
                    jmp[i] = mp(tLen, ix);
                    break;
                }
            }
            else tLen++;
        }

        // cout << "process: " << i<< " | " << cc << ' '<< tLen << '\n';
        // cout << "S[i] : " << S[i] << " => ";
        while((int)S[i].size() > cc) S[i].pop_back();
        spt[0][i] = jmp[i];
        // cout << S[i] << '\n';
    }

    for(int i = 1; i < 60; i++){
        //cout << "Go :"  << i << " | ";
        for(int j = 0;j < n;j++){
            if (spt[i-1][j].x == -1){
                spt[i][j] = mp(-1, -1);
            }
            else{
                spt[i][j].x = spt[i-1][j].x + spt[i-1][spt[i-1][j].y].x;
                spt[i][j].x = min(spt[i][j].x, (ll)4e18);
                spt[i][j].y = spt[i-1][spt[i-1][j].y].y;

              //  cout << j << " {" << spt[i][j].x << ' ' << spt[i][j].y << "} ";
            }
        }
       // cout << '\n';
    }

    for(int i=0 ; i < n;i++){
        tLen[i] = vector<ll>((int)S[i].size());
        for(int j = 0 ;j < (int)S[i].size(); j++){
            char f = S[i][j];
            if (f >= 'A' && f <= 'Z') {
                int ix = f-  'A';
                if(topo[ix] == 0) tLen[i][j] = len[ix];
                else tLen[i][j] = 4e18;
            }
            else tLen[i][j] = 1;
            if (j) tLen[i][j] += tLen[i][j-1];
            tLen[i][j] = min(tLen[i][j], (ll)4e18);
        }
    }

    while(Q--){
        int x;
        cin >> x;
        ll L, R;
        cin >> L >> R;

        int curx = x-1;
        int curIdx = 0;
        ll curLen = 0;
        
        if(topo[curx] == 0){
            stack<pair<ll, ll>> stk;

            while(curLen != L-1){
                int tl = 0, tr = (int)S[curx].size() - 1;
                int ret =- 1;
                while(tl <= tr){
                    int md = (tl+tr)>>1;
                    if (curLen + tLen[curx][md] < L){
                        ret = md;
                        tl = md + 1;
                    }
                    else tr = md - 1;
                }

                curLen += tLen[curx][ret];
                curIdx = ret + 1;
                char c = S[curx][ret+1];
                if (c >= 'A' && c <= 'Z'){
                    stk.push(mp(curx, ret+2));
                    curx = c - 'A';
                    curIdx = 0;
                }
            }

            for(int j = 0 ;j < R - L + 1; j++){
                while(curIdx == (int)S[curx].size()){
                    tie(curx, curIdx) = stk.top();
                    stk.pop();
                }

                char c = S[curx][curIdx];
                if (c >= 'A' && c <= 'Z'){
                    stk.push(mp(curx, curIdx + 1));
                    curx = c - 'A';
                    curIdx = 0;
                    c = S[curx][curIdx];
                }

                cout << c;
                curIdx++;
            }

            cout << '\n';
            while(!stk.empty()) stk.pop();

        }
        else{   
            while(curLen != L-1){
                //cout << "Go jump: " << curLen<< ' ' << L-1 << " | " << curx << endl;
                bool ok = 0;
                for(int j = 59; j >=0 ;j--){
                    auto f = spt[j][curx];
                    if (curLen + f.x < L){
                        curLen += f.x;
                        curx= f.y;
                        ok = 1;
                        break;
                    }
                }
                if (!ok) break;

            }
            stack<pair<ll, ll>> stk;
            while(curLen != L-1){
                int tl = 0, tr = (int)S[curx].size() - 1;
                int ret =- 1;
                while(tl <= tr){
                    int md = (tl+tr)>>1;
                    if (curLen + tLen[curx][md] < L){
                        ret = md;
                        tl = md + 1;
                    }
                    else tr = md - 1;
                }

                curLen += tLen[curx][ret];
                curIdx = ret + 1;
                char c = S[curx][ret+1];
                if (c >= 'A' && c <= 'Z'){
                    stk.push(mp(curx, ret+2));
                    curx = c - 'A';
                    curIdx = 0;
                }
            }
            

            for(int j = 0 ;j < R-L+1; j++){
                
                while(curIdx == (int)S[curx].size()){
                    tie(curx, curIdx) = stk.top();stk.pop();
                }

                char c = S[curx][curIdx];
                if (c >= 'A' && c <= 'Z'){
                    if (topo[c-'A'] == 0){
                        stk.push({curx, curIdx + 1});
                        curx = c - 'A';
                        curIdx = 0;
                    }
                    else{
                        curx = c-'A';
                        curIdx = 0;
                    }
                    c = S[curx][curIdx];
                }
                cout << c;
                curIdx++;
            }
            cout << '\n';

        }



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

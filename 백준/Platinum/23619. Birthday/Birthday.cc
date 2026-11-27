#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[2020];
vector<int> ans[2020];

int G[2020];
pair<int, int> rec[2020];
int D[2020];

void solve(){
    
    int n, k;
    cin >> n >> k;

    for(int i =1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            char c;
            cin >> c;
            if (c == '1') adj[i].push_back(j);
        }
    }

    queue<int> q;    

    for(int i = 1; i <= n; i++) G[i] = i;

    for(int r = 1; r <= n; r++){
        
        memset(D, -1, sizeof D);
        D[r] = 1;
        int mx = 1;
        q.push(r);
        while(!q.empty()){
            auto a = q.front(); q.pop();
            mx = max(mx, D[a]);
            for(auto  f : adj[a]){
                if (D[f] == -1){
                    D[f] = D[a] + 1;
                    q.push(f);
                }
            }
        }

        if (G[r] == r){
            for(int j = 1; j <= n; j++){
                if(D[j] != -1) G[j] = r;
            }
            rec[r] = mp(mx, r);
        }
        else{
            rec[G[r]] = max(rec[G[r]], mp(mx, r));
        }
    }

    int minn = 0;
    int maxn = 0;
    for(int i = 1; i <= n; i++){
        if (G[i] == i) {
            minn++;
            maxn += rec[i].x;
            //cout << i << " | " << rec[i].x << ' ' << rec[i].y << '\n';
        }
    }

    if (k > maxn){
        cout << "Nope\n";
        return;
    }
    
    int curK = 0;
    for(int i = 1; i<= n; i++){
        if (G[i] != i) continue;

        int r = rec[i].y;
        memset(D, -1, sizeof D);
        D[r] = 1;
        q.push(r);
        while(!q.empty()){
            auto a = q.front(); q.pop();
            for(auto  f : adj[a]){
                if (D[f] == -1){
                    D[f] = D[a] + 1;
                    q.push(f);
                }
            }
        }

        int sz = rec[i].x;
        for(int j = 1 ; j <= n; j++){
            if (D[j] == -1) continue;

            int d = D[j];
            ans[curK + d].push_back(j);
        }
        curK += sz;
    }

    for(int i = k+1; i <= maxn; i++){
        for(auto f :ans[i]) ans[k].push_back(f);
    }

    cout << "Yep\n";
    for(int i =1;i <= k; i++){
        cout << (int)ans[i].size() << ' ';
        for(auto f: ans[i]) cout << f<< ' ';
        cout << '\n';
    }

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    return 0;
}

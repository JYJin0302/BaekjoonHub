#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

vector<int> adj[202020];
int D[202020];
int maxD[202020];

vector<int> qur[202020];

void dfs(int v, int pv = -1){
    auto iter = find(all(adj[v]), pv);
    if(iter != adj[v].end()){
        adj[v].erase(iter);
    }

    for(auto f : adj[v]){
        D[f] = D[v] + 1;
        dfs(f, v);
    }
    maxD[v] = D[v];
    if(adj[v].empty()){
        // ok
    }
    else {
        int L = adj[v][0], R;
        if ((int)adj[v].size() == 1) R = v;
        else R = adj[v][1];

        //cout << "Check : " << v << " | " << maxD[L] << ' ' << maxD[R] << '\n';

        if(maxD[L] > maxD[R] + 1){
            //cout << "Qur: "<< L << " | "<< maxD[R] + 2 << '\n';
            qur[L].push_back(maxD[R] + 2);
            maxD[v] = maxD[R] + 1;
        }
        else if(maxD[R] > maxD[L] + 1){
            //cout << "Qur: " << R << " | " << maxD[L] + 2 << '\n';
            qur[R].push_back(maxD[L] + 2);
            maxD[v] = maxD[L] + 1;
        }
        else{
            maxD[v] = max(maxD[L], maxD[R]);
        }
    }
}

int track[202020];
int ans = 0;
void getAns(int v, bool isE = 0){
    if(isE || track[D[v]]){
        ans++;
        //cout << "CHeck: " << v << "\n";
        for(auto f: adj[v]){
            getAns(f, 1);
        }
        return;
    }

    for(auto f: qur[v]){
        track[f]++;
    }

    for(auto f :adj[v]){
        getAns(f);
    }

    for(auto f: qur[v]){
        track[f]--;
    }
}

void solve(){
    
    int n;
    cin >> n;
    for(int i =0 ; i< n-1 ;i++){
        int a, b;
        cin >> a>> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    D[1] = 1;
    dfs(1);

    getAns(1);

    cout << ans << '\n';
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


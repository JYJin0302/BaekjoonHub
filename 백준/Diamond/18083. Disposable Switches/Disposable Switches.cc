#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<ll, ll>> adj[2010];

ll dp[2010][2010];
// dp[a][b] : node a에 b 번 거쳐 가는 경우 최소길이
ll ok[2010][2010];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    int n, m;
    cin >>n >>m;

    for(int i =0 ; i<m; i++){
        ll a, b, c;
        cin >>a >>b >>c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for(int i = 1; i <= n ;i++){
        for(int j= 0; j <= n; j++){
            dp[i][j] = 1e15;
        }
    }

    priority_queue<tuple<ll, int, int>> pq;
    pq.push({0, 1, 0});
    vector<ll> tmpAns(n+1, n+1);
    tmpAns[1] = 0;

    while(!pq.empty()){

        ll a, b, c;
        tie(a, b, c) = pq.top();
        pq.pop();

        if (dp[b][c] != 1e15)continue;
        tmpAns[b] = min(tmpAns[b], c);
        dp[b][c] = -a;
        if(c == n-1) continue;


        for(auto i : adj[b]){

            ll x, y;
            tie(x, y)= i;

            if (dp[x][c+1] == 1e15 && tmpAns[x] > c+1){
                pq.push({a-y, x, c+1});
            }
        }
    }
    for(int i = 1; i<= n; i++){
        ll mv = 1e15;
        for(int j = 0; j < n; j++){
            if (dp[i][j] > mv) dp[i][j] = 1e15;
            mv = min(dp[i][j], mv);
        }
    }

    vector<pair<ll, ll>> wtf(n);
    int ix = 0;
    while(dp[n][ix] == 1e15) ix++;
    int sx = ix;
    wtf[sx] = {1, 1e15};
    ix++;
    while(ix <n){

        if(dp[n][ix] == 1e15){
                ix++;
                continue;
        }
        pair<ll, ll> tmp = {1, 1e15};
        for(int j = 0;j <ix; j++){

            if (dp[n][j] == 1e15)continue;
            pair<ll, ll> t2 = {ix-j, dp[n][j] - dp[n][ix]};

            if(tmp.first *t2.second <= tmp.second*t2.first) swap(tmp, t2);
        }

        for(int j = sx; j < ix; j++){
            if(tmp.first *wtf[j].second < tmp.second * wtf[j].first) dp[n][j] = 1e15;
        }
        //cout << ix <<' ' <<tmp.first <<' ' << tmp.second <<'\n';
        wtf[ix] = tmp;
        ix++;
    }

    //for(int i = 1; i<= n; i++){
    //    for(int j = 0; j < n; j++){
    //        if (dp[i][j] == 1e15)cout <<"X ";
    //        else cout <<dp[i][j] <<' ';
    //    }
    //    cout <<'\n';
    //}

    queue<pair<int, int>>q;
    for(int i= 0; i < n; i++){
        if (dp[n][i] != 1e15){
            ok[n][i] = 1;
            q.push({n, i});
        }
    }

    while(!q.empty()){

        int b, c;
        tie(b, c) = q.front();
        q.pop();

        if(c == 0)continue;
        for(auto i :adj[b]){
            ll x,y;
            tie(x, y)= i;

            if (dp[x][c-1] + y == dp[b][c] && !ok[x][c-1]){
                ok[x][c-1] = 1;
                q.push({x, c-1});
            }
        }

    }

    vector<int> ans;
    for(int i = 1; i <= n; i++){
        bool valid = 0;
        for(int j = 0; j <n; j++){
            if(ok[i][j]) valid = 1;
        }
        if(!valid) ans.push_back(i);
    }

    cout <<ans.size()<< '\n';
    for(auto i :ans)cout <<i <<' ';
}

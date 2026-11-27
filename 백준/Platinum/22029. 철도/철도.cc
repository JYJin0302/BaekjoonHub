#include "railroad.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[222];

std::vector<std::pair<int, int>> encode_map(int N, int K, int &X, std::vector<std::pair<int, int>> E) {
    vector<pair<int, int>> ret;
    
    for(int i = 1; i <= N;i ++) adj[i].clear();
    for(auto[a,b] : E) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int D = 10101, ansi = -1;
    for(int i = 1;  i<= N; i++){
        vector<int> dist(N+1, -1);
        dist[i] = 0;

        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int a= q.front(); q.pop();
            for(auto f: adj[a]) if (dist[f] == -1){
                dist[f] = dist[a] + 1;
                q.push(f);
            }
        }

        int md= *max_element(all(dist));

        if (D > md){
            D = md;
            ansi = i;
        }
    }

    // bfs from ansi
    vector<bool> vis(N+1);
    vis[ansi] = 1;
    queue<int> q;
    q.push(ansi);
    for(int i = 1; i <= D && K; i++){
        vector<int> tmp;
        while(!q.empty()){
            int a= q.front(); q.pop();
            for(auto v : adj[a]) if (!vis[v]){
                vis[v] = 1;
                tmp.push_back(v);
            }
        }

        int sn = (int)tmp.size();
        for(int a = 0 ;a < sn && K; a++){
            for(int b=  a +1 ;b < sn && K; b++){
                K--;
                ret.push_back(mp(tmp[a], tmp[b]));
            }
        }

		for(auto f : tmp) q.push(f);
    }
	assert(K == 0);

    X = ansi;
    return ret;
}

std::vector<std::pair<int, int>> decode_map(int N, int K, int X, std::vector<std::pair<int, int>> E){
    vector<pair<int, int>> ret;
    for(int i = 1; i <= N; i++) adj[i].clear();
    for(auto[a,b] : E) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(N+1, -1);
    dist[X] = 0;
    queue<int> q;
    q.push(X);
    while(!q.empty()){
        auto f = q.front(); q.pop();

        for(auto v : adj[f]){
            if (dist[v] == -1){
                dist[v] = dist[f] + 1;
                ret.push_back(mp(f, v));
                q.push(v);
            }
        }
    }
    return ret;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<int, int>>adj[101010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, l, r;
    cin >>n >>m >> l >> r;

    for(int i = 0; i <m;i++){
        int a, b, c;
        cin >> a >>b >>c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int ans = 0;
    vector<int> dist(n+1, -1);
    priority_queue<pair<int, int>> pq;
    map<pair<int, int>, bool> check;

    pq.push({0, 0});
    while(!pq.empty()){

        int a, b;
        tie(a,b)= pq.top();
        pq.pop();

        if (dist[b] != -1)continue;
        dist[b] = -a;

        if (2*dist[b] >= r) continue;

        for(auto i :adj[b]){
            int x, y;
            tie(x, y) = i;

            if(!check[{b, x}] && !check[{x, b}]){
                ans++;
                check[{b, x}] = 1;
                check[{x, b}] = 1;
            }

            if(dist[x] == -1){
                pq.push({a-y, x});
            }
        }
    }
    cout <<ans;
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;


vector<int> adj[101010];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >>m;

    while(m--){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(n+1, -1);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    int cnt = 0, mDist = 0;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        mDist = dist[a];
        cnt++;
        for(auto i : adj[a]) if(dist[i] == -1){
            dist[i] = dist[a] + 1;
            q.push(i);
        }
    }

    if (cnt != n){
        cout << -1;
        return 0;
    }

    cout << (int)(ceil(log2(mDist))+0.5)+1;


}

#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

vector<pair<int, int>> adj[100001];

int p1[100001], p2[100001], p3[100001], dist[100001]; 
// 현재 노드를 루트로 하는 서브트리를 순회하는 길이 + p1: 도착점 상관없음, p2: 원래 자리로 돌아옴
// p3: 도착점 상관없고 두개로 시작, dist : 루트에서 해당 노드까지의 거리

void dfs(int v, int pv = -1){
    
    int mv2 = 0;
    priority_queue<int> pq;
    for(auto k : adj[v]) if (k.x != pv){
        dist[k.x] = dist[v] + k.y;
        dfs(k.x, v);
        p2[v] += k.y*2 + p2[k.x];
        pq.push(p1[k.x] - p2[k.x] - k.y);
        mv2 = min(mv2,p3[k.x] - p2[k.x]);
        if (pq.size() > 2) pq.pop();
    }
    int mv1 = 0;
    if (pq.size() == 2){
        int t = pq.top();
        pq.pop();
        mv1 = pq.top();
        pq.pop();
        pq.push(t);
    }
    else if (pq.size() == 1){
        mv1 = pq.top();
        pq.pop();
    }
    p1[v] = p2[v] + mv1;
    
    mv1 = 0;
    if (!pq.empty()) mv1 = pq.top();
    p3[v] = p1[v] + mv1;
    p3[v] = min(p3[v], p2[v] + mv2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, s;
    cin >> n >> s;
    
    for (int i = 0; i < n-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    dfs(s);
    
    cout << p3[s];
}
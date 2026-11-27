#include <bits/stdc++.h>
using namespace std;

const int INF = 100000;

map<int, int> itox;  // int to index
map<int, int> xtoi;  // index to int

bool p[10001];

int main(){
    
    for (int i = 2; i < 10000; i++) p[i] = 1;
    
    for (int i = 2; i < 10000; i++){
        if (p[i]){
            for (int j = i*2; j <= 10000; j += i) p[j] = 0;
        }
    }
    
    int cnt = 0;
    for (int i = 1000; i < 10000; i++){
        if (p[i]) {
            cnt++;
            itox[i] = cnt;
            xtoi[cnt] = i;
        }
    }
    
    
    int t;
    cin >> t;
    while(t--){
        
        int x, y;
        cin>> x >> y;
        vector<int> dist(cnt + 1, INF);
        
        int idx = itox[x];
        dist[idx] = 0;
        
        queue<int> q;
        q.push(x);
        while(!q.empty()){
            
            int a = q.front();
            q.pop();
            
            if (a == y) break;
            
            // 천의자리
            for (int i = 1; i < 10; i++){
                int na = a % 1000 + 1000 * i;
                if (na != a && p[na] && dist[itox[na]] == INF){
                    dist[itox[na]] = dist[itox[a]] + 1;
                    q.push(na);
                }
            }
            
            // 백
            for(int i = 1; i < 10; i++){
                int na = a + 100 * i;
                na = na % 1000 + a / 1000 * 1000;
                if (na != a && p[na] && dist[itox[na]] == INF){
                    dist[itox[na]] = dist[itox[a]] + 1;
                    q.push(na);
                }
            }
            
            // 십
            for(int i = 1; i < 10; i++){
                int na = a + 10 * i;
                na = na % 100 + a / 100 * 100;
                if (na != a && p[na] && dist[itox[na]] == INF){
                    dist[itox[na]] = dist[itox[a]] + 1;
                    q.push(na);
                }
            }
            
            // 일
            for(int i = 1; i < 10; i++){
                int na = a +  i;
                na = na % 10 + a / 10 * 10;
                if (na != a && p[na] && dist[itox[na]] == INF){
                    dist[itox[na]] = dist[itox[a]] + 1;
                    q.push(na);
                }
            }
        }
        
        if (dist[itox[y]] == INF) cout << "Impossible\n";
        else cout << dist[itox[y]] << '\n';
    }    
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point{
     ll x, y, r;  
};

vector<int> root;

int find(int n){
    if (n == root[n]) return n;
    return root[n] = find(root[n]);
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cout << fixed << setprecision(6);
    int t;
    cin >> t;
    while(t--){
        
        int w;
        cin >> w;
        
        int n;
        cin >> n;
        
        root = vector<int>(n+2); // 0: 왼쪽 벽, n+1: 오른쪽 벽
        for(int i = 0; i <= n+1; i++) root[i] = i;
        
        vector<tuple<double, int ,int>> edge;
        vector<Point> p(n);
        
        edge.push_back({w, 0, n+1});
        
        int tcnt = 1;
        for(auto& i : p){
            cin >> i.x >> i.y >> i.r;
            
            edge.push_back({max(0.0, double(i.x - i.r)), 0, tcnt});
            edge.push_back({max(0.0, double(w - i.x - i.r)), tcnt, n+1});
            tcnt++;
        }
        
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                
                double dist = sqrtl((p[i].x - p[j].x) * (p[i].x - p[j].x) + \
                                   (p[i].y - p[j].y) * (p[i].y - p[j].y));
                dist = max(0.0, dist - p[i].r - p[j].r);
                
                edge.push_back({dist, i+1, j+1});
            }
        }
        
        sort(edge.begin(), edge.end());
        
        double ans = 0;
        for (auto i : edge){
            
            double d;
            int x, y;
            tie(d, x, y) = i;
            
            find(x), find(y);
            find(0), find(n+1);
            
            if (root[x] != root[y]){
                root[root[x]] = root[y];
                tcnt++;
                
                if (find(0) == find(n+1)){
                    ans = d/2;
                    break;
                }
            }
        }
        
        cout << ans << '\n';
    }
}
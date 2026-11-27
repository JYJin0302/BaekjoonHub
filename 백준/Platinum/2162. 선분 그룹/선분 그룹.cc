#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Point{
    ll x, y;
};

bool isInLine(Point p1, Point p2, Point t){
    if (t.x > max(p1.x, p2.x) || t.x < min(p1.x, p2.x)) return 0;
    if (t.y > max(p1.y, p2.y) || t.y < min(p1.y, p2.y)) return 0;
    
    return (p1.x - t.x) * (p2.y - t.y) == (p2.x - t.x) * (p1.y - t.y);
}

ll ccw(Point a, Point b, Point c){
    ll v = (a.x * b.y + b.x * c.y + c.x*a.y) - (a.y * b.x + b.y * c.x + c.y* a.x);
    if (v > 0) return 1;
    if (v < 0) return -1;
    return 0;
}

bool isCollide(Point p1, Point p2, Point p3, Point p4){
    bool ok = 0;
    // 접하듯 겹치는 경우
    ok = isInLine(p1, p2, p3) || isInLine(p1, p2, p4);
    ok = ok || isInLine(p3, p4, p1) || isInLine(p3, p4, p2);
    
    // 교차하는 경우
    ok = ok || (ccw(p1, p2, p3) * ccw(p1, p2, p4) < 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) < 0);
    
    return ok;
}

int root[3001];
int sz[3001];
int find(int n){
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<Point, Point>> p(n);
    for(auto& i : p) cin >> i.first.x >> i.first.y >> i.second.x >> i.second.y;
    
    for (int i = 0; i < n; i++){
        sz[i] = 1;
        root[i] = i;
    }
    
    for (int i =0 ; i < n; i++){
        for (int j = i+1; j < n; j++){
            bool ok = isCollide(p[i].first, p[i].second, p[j].first, p[j].second);
            
            if (ok){
                find(i), find(j);
                if (root[i] != root[j]){
                    sz[root[i]] += sz[root[j]];
                    root[root[j]] = root[i];
                }
            }
        }
    }
    
    vector<int> ans;
    for(int i = 0; i < n; i++){
        find(i);
        if (root[i] == i) ans.push_back(sz[i]);
    }
    
    cout << ans.size() << '\n';
    cout << *max_element(ans.begin(), ans.end());
    
}
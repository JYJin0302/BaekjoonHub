#include <bits/stdc++.h>
using namespace std;

int sx, sy;
struct Point{
    int x, y;
    bool operator<(Point& A){
        if (x == A.x) return y < A.y;
        return x < A.x;
    }
};

const double PI = 3.1415926535;

bool cmp(Point& w, Point& z){
    if ((w.y - sy) * (z.x - sx) != (z.y - sy) * (w.x - sx))
            return (w.y - sy) * (z.x - sx) < (z.y - sy) * (w.x - sx);
    if (w.x == z.x) return w.y < z.y;
    return w.x < z.x;
}

int ccw(Point a, Point b, Point c){
    return a.x*b.y + b.x*c.y + c.x*a.y - (a.y*b.x + b.y*c.x + c.y*a.x);
}

double dist(Point a, Point b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) * 1.0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, l;
    cin >> n >> l;
    
    vector<Point> p(n);
    for(auto& i : p){
        cin >> i.x >> i.y;
    }
    
    sort(p.begin(), p.end());
    sx = p[0].x, sy = p[0].y;
    sort(p.begin(), p.end(), cmp);
    
    stack<Point> st;
    st.push(p[0]);
    
    for (auto k : p){
        
        while(st.size() >= 2){
            Point p2 = st.top();
            st.pop();
            Point p1 = st.top();
            
            if (ccw(p1, p2, k) > 0) {
                st.push(p2);
                break;
            }
        }
        st.push(k);
    }
    
    vector<Point> ch;
    while(!st.empty()){
        Point a = st.top();
        ch.push_back(a);
        st.pop();
    }
    
    int sz = ch.size();
    double ans = 0;
    for (int i = 0; i < sz; i++){
        ans += dist(ch[i], ch[(i+1) % sz]);
    }
    ans += 2*PI *l;
    
    cout << floor(ans + 0.5);
    
}
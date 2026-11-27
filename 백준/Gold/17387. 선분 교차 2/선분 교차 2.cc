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

int main(){
    
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    cin >> p4.x >> p4.y;
    
    bool ok = 0;
    // 접하듯 겹치는 경우
    ok = isInLine(p1, p2, p3) || isInLine(p1, p2, p4);
    ok = ok || isInLine(p3, p4, p1) || isInLine(p3, p4, p2);
    
    // 교차하는 경우
    ok = ok || (ccw(p1, p2, p3) * ccw(p1, p2, p4) < 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) < 0);
    
    cout << ok;
}
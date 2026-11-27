#include <bits/stdc++.h>
using namespace std;

struct P{
    int x, y;
};
P A[4], B[4];
P d;

P a1, a2, b1, b2;

int mul(P& a, P& b){
    return abs(a.x*b.x + a.y*b.y);
}

bool check(P& u){
    return mul(d, u) >= mul(a1, u) + mul(a2, u) + mul(b1, u) + mul(b2, u);
}

int main(){
    
    for(int i = 0; i < 4; i++){
        cin >> A[i].x >> A[i].y;
    }
    for(int i = 0; i < 4; i++){
        cin >> B[i].x >> B[i].y;
    }
    
    a1 = {A[1].x - A[0].x, A[1].y - A[0].y};
    a2 = {A[2].x - A[1].x, A[2].y - A[1].y};
    b1 = {B[1].x - B[0].x, B[1].y - B[0].y};
    b2 = {B[2].x - B[1].x, B[2].y - B[1].y};
    
    P mA = {A[0].x + A[2].x, A[0].y + A[2].y};
    P mB = {B[0].x + B[2].x, B[0].y + B[2].y};
    
    d = {mA.x - mB.x, mA.y - mB.y};
    
    bool ok = 0;    
    ok |= check(a1);
    ok |= check(a2);
    ok |= check(b1);
    ok |= check(b2);
    
    if (ok) cout << 0;
    else cout << 1;
}
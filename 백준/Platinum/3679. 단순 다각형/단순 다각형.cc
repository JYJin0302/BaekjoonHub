#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const double PI = 3.1415926535;

struct point{
    ll x, y;
    int idx;
};

vector<point> Ap, P;
int pidx = 0;

bool cmp_1(point& A, point& B){
    if (A.x == B.x) return A.y < B.y;
    return A.x < B.x;
}

bool cmp_2(point& A, point& B){
    double a1 = PI/2, a2 = PI / 2;
    
    if (A.x != P[pidx].x) a1 = atan((double)(A.y - P[pidx].y) / (A.x - P[pidx].x));
    if (B.x != P[pidx].x) a2 = atan((double)(B.y - P[pidx].y) / (B.x - P[pidx].x));
    
    if (a1 != a2) return a1 < a2;
    
    double d1, d2;
    d1 = sqrt((P[pidx].x - A.x)*(P[pidx].x - A.x) + (P[pidx].y - A.y)*(P[pidx].y - A.y));
    d2 = sqrt((P[pidx].x - B.x)*(P[pidx].x - B.x) + (P[pidx].y - B.y)*(P[pidx].y - B.y));
    
    return d1 < d2;
}

int ccw(point a, point b, point c){
    return a.x * b.y + b.x * c.y + c.x * a.y - (a.y * b.x + b.y * c. x + c.y * a.x);
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        
        P = vector<point> (n);
        Ap = vector<point> (n);
        for (int i = 0; i < n; i++){
            cin >> P[i].x >> P[i].y;
            P[i].idx = i;
            
            Ap[i] = P[i];
        }
        
        
        sort(Ap.begin(), Ap.end(), cmp_1);
        pidx = Ap[0].idx;
        sort(Ap.begin(), Ap.end(), cmp_2);
                
        int e = n - 3;
        while(ccw(Ap[e], Ap[e+1], Ap[e+2]) == 0) e--;
        
        for (int i = 0; i <= e; i++) if (Ap[i].idx != pidx) cout << Ap[i].idx << ' ';
        for (int i = n-1; i > e; i--) if (Ap[i].idx != pidx) cout << Ap[i].idx << ' ';
        cout << pidx << '\n';
    }
}
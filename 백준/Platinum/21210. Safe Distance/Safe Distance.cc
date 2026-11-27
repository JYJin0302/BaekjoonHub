#include <bits/stdc++.h>
#define ll long long
using namespace std;
using ld = long double;

struct P{
    ld x, y;
};

ld dist(P p1, P p2){
    return sqrtl((p1.x-p2.x)*(p1.x-p2.x) +(p1.y-p2.y)*(p1.y-p2.y));
}

int root[1020];
int find(int n){
    if(root[n] == n) return n;
    return root[n] = find(root[n]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ld x, y;
    cin >>x >> y;

    int n;
    cin >>n;
    vector<P> A(n);
    for(auto&i :A) cin >>i.x >>i.y;

    ld l = 0, r = x+y;
    P origin = {0, 0};
    P target = {x, y};

    vector<tuple<ld, int, int>> edge;
    for(int i = 0; i <n;i++){
        edge.push_back({A[i].x, i, n+3});
        edge.push_back({x-A[i].x, i, n+1});
        edge.push_back({A[i].y, i, n});
        edge.push_back({y-A[i].y, i, n+2});
        for(int j = i+1; j < n; j++){
            edge.push_back({dist(A[i], A[j])/2, i, j});
        }
    }
    edge.push_back({0, n+1, n});
    edge.push_back({0, n+2, n+3});
    sort(edge.begin(), edge.end());

    ld ans = 0;
    while(r-l > 1e-7){

        ld mid = (r+l)/2;

        bool ok = 1;

        for(int i = 0; i < n; i++){
            if(dist(A[i], origin) < mid) ok = 0;
            if(dist(A[i], target) < mid) ok = 0;
        }
        if(!ok){
            r = mid;
            continue;
        }

        for(int i = 0; i <= n+3; i++){
            root[i] = i;
        }

        for(auto i : edge){
            ld len;
            int a, b;
            tie(len, a, b) = i;

            if(len > mid) break;

            a = find(a), b= find(b);
            root[a] = b;
        }

        int t1 = n+1, t2=  n+2;
        t1 = find(t1), t2 = find(t2);

        if (t1 == t2) ok = 0;

        if (ok) {
            ans = mid;
            l = mid;
        }
        else r = mid;

    }
    cout << setprecision(10);
    cout <<ans;
}

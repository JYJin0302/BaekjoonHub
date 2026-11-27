#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int fw[101010];
void update(int ix, int val){
    while(ix <= 100010){
        fw[ix] += val;
        ix += ix & -ix;
    }
}
int getS(int ix){
    int res = 0;
    while(ix){
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}

void solve(){
    
    int p, v;
    cin >> p >> v;
    
    vector<array<int, 3>> P;
    for(int i =0;i < p ;i++){
        int a, b;
        cin >> a>> b;
        P.push_back({b, a, i+1});
    }
    sort(all(P));

    vector<int> xpos, ypos;

    vector<pair<int, int>> V;
    for(int i =0; i <v; i++){
        int a, b;
        cin >> a>> b;
        V.push_back(mp(a, b));
        xpos.push_back(a);
        ypos.push_back(b);
    }

    xpos.push_back(-1e9-10);
    sort(all(xpos));
    xpos.erase(unique(all(xpos)), xpos.end());
    ypos.push_back(-1e9-10);
    sort(all(ypos));
    ypos.erase(unique(all(ypos)), ypos.end());

    for(auto&[a,b] : V){
        a = lower_bound(all(xpos), a) - xpos.begin();
        b = lower_bound(all(ypos), b) - ypos.begin();
    }

    vector<array<int, 3>> B;
    for(int i =0 ;i < v; i++){
        int ni = (i+1) % v;
        if (V[i].y == V[ni].y) continue;

        int l = V[i].y, r = V[ni].y;
        if (l > r) swap(l, r);

        B.push_back({l, V[i].x, 1});
        B.push_back({r, V[i].x, -1});
    }
    sort(all(B));

    ll ans = 0;
    int i1 = 0, i2 = 0;
    while(i1 < p && i2 < (int)B.size()){
        int curY1 = P[i1][0];
        int curY2 = ypos[B[i2][0]];
        if(curY1 <= curY2){
            // get Ans
            auto idx = lower_bound(all(xpos), P[i1][1]) - xpos.begin();
            int res= getS(idx-1);
            if(res & 1) {}
            else ans += P[i1][2];
            i1++;
        }
        else{
            update(B[i2][1], B[i2][2]);
            i2++;
        }
    }

    while(i1 < p){
        ans += P[i1][2];
        i1++;
    }

    cout << ans << '\n';
    
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }   
    return 0;
}
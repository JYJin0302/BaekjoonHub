
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second


map<pair<int, int>, bool> isWell;
pair<int, int> A[1010], L[1010], R[1010];

vector<int> adj[2020];
int scc[2020];
int dfsn[2020];
stack<int> st;

int o = 1;

int dfs(int v ,int pv = -1){
    dfsn[v] = o++;
    st.push(v);
    int ret = dfsn[v];
    for(auto f :adj[v]){
        if (dfsn[f] == -1){
            ret = min(ret, dfs(f));
        }
        else{
            if (scc[f] == -1) ret = min(ret, dfsn[f]);
        }
    }

    if (ret == dfsn[v]){

        while(!st.empty()){
            int a =st.top();
            st.pop();

            scc[a] = v;
            if (a == v) break;
        }

    }
    return ret;
}


int ccw(pair<int, int> p1, pair<int, int> p2, pair<int,int> p3){

    int res = p1.x *p2.y +p2.x*p3.y+p3.x*p1.y;
    res -= p1.y*p2.x + p2.y *p3.x + p3.y *p1.x;

    if (res != 0) res /= abs(res);
    return res;
}

ll gcd(ll a, ll b){
    if(a > b)swap(a, b);

    if (a == 0) return b;
    return gcd(b% a, a);
}

bool isConn(int i, int j){

    // intersection at not well

    //cout << "conn:"<< i <<' ' <<j << '\n';
    pair<int, int> res = mp(-1, -1);
    if(L[i] == R[j] || L[i] == L[j]) res = L[i];
    else if(R[i] == R[j] || R[i] == L[j]) res = R[i];
    else{

        int val1 = ccw(L[i], R[i], L[j]);
        int val2 = ccw(L[i], R[i], R[j]);

        if (val1*val2 != -1) return 0;
        //cout << "Chk1\n";

        val1 = ccw(L[j], R[j], L[i]);
        val2 = ccw(L[j], R[j], R[i]);

        if (val1*val2 != -1) return 0;
        //cout <<"Chk2\n";

        ll a = R[i].y - L[i].y;
        ll b = L[i].x - R[i].x;
        ll c = -1 *(a*L[i].x + b * L[i].y);

        ll g = gcd(gcd(abs(a), abs(b)), abs(c));

        if (g) a /= g, b /= g, c /= g;

        ll ta = a * (L[j].x - R[j].x)+ b*(L[j].y - R[j].y);
        ll tb = a * R[j].x + b * R[j].y + c;
        tb *= -1;

        if(ta == 0) return 1;

        g = gcd(abs(ta), abs(tb));
        if(g) ta/= g, tb /= g;

        if(abs(L[j].x - R[j].x) % abs(ta) != 0) return 1;
        if(abs(L[j].y - R[j].y) % abs(ta) != 0) return 1;

        res.x = (L[j].x - R[j].x) / ta * tb + R[j].x;
        res.y = (L[j].y - R[j].y) / ta * tb + R[j].y;


    }

    //cout <<res.x <<' ' <<res.y <<'\n';

    if (isWell[res]) return 0;
    return 1;

}


void solve(){
    int w, p;
    cin >>w >>p;

    for(int i =1 ; i <= w; i++) {
        int a, b;
        cin >>a >>b;

        A[i] = mp(a, b);
        isWell[A[i]] = 1;
    }

    for(int j = 1; j <= p; j++){
        int a, b ,c;
        cin >> a >> b >> c;

        L[j] = A[a];
        R[j] = mp(b, c);
    }

    for(int i = 1; i <= p; i++){
        for(int j = i+1; j <= p; j++){

            if (isConn(i, j)){

                //cout << "Go:"<< i << ' ' <<j <<'\n';
                adj[i].push_back(j+p);
                adj[j].push_back(i+p);

                adj[i+p].push_back(j);
                adj[j+p].push_back(i);
            }

        }
    }
    for(int i =1 ; i <= p*2; i++) {
        dfsn[i] = scc[i] = -1;
    }

    for(int i =1 ; i <= p*2; i++) {
        if (dfsn[i]==-1)dfs(i);
    }


    bool ok = 1;
    for(int i = 1; i <= p ;i++){
        if (scc[i] == scc[i+p]) ok = 0;
    }

    if (ok) cout << "possible";
    else cout << "impossible";
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

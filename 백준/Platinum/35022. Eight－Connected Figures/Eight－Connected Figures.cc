#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define rep(i,a,b) for (int i=a;i<(b);++i)

#define mp make_pair

//mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef long long ll;
int n;


int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1};

char G[2020][2020];

char ask(int i, int j){
    if (G[i][j] != '?') return G[i][j];
    cout << "? " << i << ' ' << j << endl;
    char c;
    // int v = rng() % 2;
    // if(v) c = 'W';
    // else c = 'B';
    cin >> c;
    return G[i][j] = c;
}



void solve(){
    
    int b = 1010;


    vector<pair<int, int>> W, B;

    char c = ask(b, b);
    if (c == 'W'){
        W.push_back(mp(b, b));
    }
    else{
        B.push_back(mp(b, b));
    }

    set<pair<int, int>> st;
    for(int i =0; i < 8; i++){
        st.insert(mp(b + dx[i], b + dy[i]));
    }

    while((int)W.size() < n && (int)B.size() < n){

        array<int, 3> nxt = {-1, 0, 0};
        for(auto [a,b] : st){
            
            int v = 0;
            for(int i = 0; i < 8; i++){
                int na = a + dx[i];
                int nb = b + dy[i];

                if (G[na][nb] == '?') continue;
                if (G[na][nb] == 'W') v |= 2;
                if (G[na][nb] == 'B') v |= 1;
            }

            nxt = max(nxt, {v, a, b});
        }

        if (nxt[0] == 1){
            W.clear();
        }
        else if (nxt[0] == 2){
            B.clear();
        }

        int a = nxt[1], b = nxt[2];
        st.erase(st.find(mp(a, b)));
        char c = ask(a, b);
        if(c == 'W') W.push_back(mp(a, b));
        else B.push_back(mp(a, b));

        for(int f = 0 ;f < 8; f++){
            int na = a + dx[f];
            int nb = b + dy[f];
            if (G[na][nb]== '?') st.insert(mp(na, nb));
        }
    }

    if((int)B.size() == n){
        cout << "! B ";
        for(auto[a,b] : B) cout << a<< ' '<< b << ' ';
        cout << endl;
    }
    else{
        cout << "! W ";
        for(auto[a,b] : W) cout << a<< ' '<< b << ' ';
        cout << endl;
    }

    // for(int i = -20; i <= 20; i++){
    //     for(int j = -20; j <= 20; j++){
    //         cout << G[b+i][b+j];
    //     }
    //     cout << '\n';
    // }

}


int main(){ 
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;
    cin >> t >> n;
    while(t--){
        memset(G, '?', sizeof G);
        solve();
    }
    return 0;
}
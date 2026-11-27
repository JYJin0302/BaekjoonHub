#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define all(x) x.begin(), x.end()

int nxt[52];
int topo[52];

bool backdoor = 0;
int ans = 0;
bool vis[52];

int getIdx(char c){
    if(c >= 'a' && c <= 'z') return c- 'a';
    return 26 + c - 'A';
}
void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();

    memset(nxt, -1 ,sizeof nxt);
    backdoor = 0;
    ans = 0;
    for(int i = 0; i < 52; i++){
        vis[i] = 0;
        topo[i] = 0;
    }

    for(int i = 0; i < n;i++){
        int u = getIdx(s1[i]);
        int v = getIdx(s2[i]);
        
        if (nxt[u] == -1 || nxt[u] == v){
            nxt[u] = v;
        }
        else {
            cout << -1 << '\n';
            return;
        }
    }

    for(int i = 0; i < 52; i++){
        if (nxt[i] == -1) backdoor = 1;
        if (nxt[i] != -1 && nxt[i] != i) {
            ans++;
            topo[nxt[i]]++;
        }
    }

    //cout << ans << endl;
    queue<int> q;
    for(int i= 0 ;i < 52;i ++){
        if (topo[i] == 0 && nxt[i] != -1) q.push(i);
    }
    vector<int> tmp;
    while(!q.empty()){
        int a= q.front(); q.pop();

        int nx = nxt[a];
        if (nx == a || nx == -1) continue;
        backdoor = 1;
        topo[nx]--;
        if (topo[nx] == 0) q.push(nx);
        else tmp.push_back(nx);
    }

   // cout << ans << endl;
   for(auto i : tmp){
        if (topo[i] > 0){
            int ti = i;
            while(1){
                topo[ti] = 0;
                ti = nxt[ti];
                if (ti == -1 || ti == i) break;
            }
        }
    }

    for(int i = 0; i < 52; i++){
        if (topo[i] > 0){
            if (!backdoor){
                cout << -1 << '\n';
                return;
            }
            ans++;
            int ti = i;
            while(1){
                topo[ti] = 0;
                ti = nxt[ti];
                if (ti == -1 || ti == i) break;
            }
        }
    }   
    cout << ans << '\n';


}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
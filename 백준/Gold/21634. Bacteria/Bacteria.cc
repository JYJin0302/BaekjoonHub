#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

map<string, bool> used;
int getCnt(string s){
    int n = (int)s.size();
    queue<pair<int, int>> q;
    q.push(mp(0, n-1));
    int ret =0;
    while(!q.empty()){
        auto[a,b] =q.front(); q.pop();

        string tmp = s.substr(a, b-a+1);
        if (!used[tmp]){
            used[tmp] = 1;
            ret++;
        }

        if (a != b){
            int md = (a+b)>>1;
            q.push(mp(a, md));
            q.push(mp(md+1, b));
        }
    }
    return ret;
}

void solve(){
    
    int n;
    cin >> n;

    vector<int> C = {1, 3, 6, 11, 20};

    int tar = 0;
    int len = 0;
    for(int i = 0;i < 5; i++){
        if (C[i] <= n){
            tar = C[i];
            len = 1 << i;
        }
    }

    vector<string> lst;
    for(int i =0 ;i  < (1 << len); i++){
        string s;
        for(int j = 0; j < len ;j++){
            if(i & (1 << j)) s += '1';
            else s += '0';
        }
        lst.push_back(s);
    }
    sort(all(lst));

    int cnt = (1 << n) / len;

    map<pair<int, int>, bool> usd;
    string ans;

    int cc = 0;
    for(int i =0 ;  i< (int)lst.size(); i += 2){
        for(auto f: lst[i]) ans += f;
        for(auto f: lst[i+1]) ans += f;
        usd[mp(i, i+1)] = 1;
        cc += 2;
    }

    for(int i = 0; i < (int)lst.size() &&cc < cnt; i++){
        for(int j = 0; j < (int)lst.size() && cc < cnt; j++){
            if (usd[mp(i, j)]) continue;
            cc += 2;
            for(auto f : lst[i]) ans += f;
            for(auto f : lst[j]) ans += f;
        }
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

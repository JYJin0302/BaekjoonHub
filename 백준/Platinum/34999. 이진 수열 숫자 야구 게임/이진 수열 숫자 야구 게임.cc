#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int n;
int qCnt = 0;

int P[4040];

int ask(string s){
    qCnt++;
    cout << "? " << s << endl;
    int x = 0;
    cin >> x;
    // for(int j = 0; j < n; j++){
    //     if (target[j] == s[j]) x++;
    // }
    return x;
}

bool ans[4040];
int val;
void search(int l, int r, int cnt1){
    if (l > r || cnt1 == 0) return;
    if (r - l + 1 == cnt1){
        for(int i = l; i <= r; i++) ans[P[i]] = 1;
        return;
    }

    int md = (l+r)>>1;
    string tmp(n, '0');
    for(int i = l; i <= md; i++){
        tmp[P[i]] = '1';
    }

    int res = ask(tmp);

    int dif = res - val;

    int nc1 = (dif + md - l + 1) >> 1;
    search(l, md, nc1);
    search(md+1, r, cnt1 - nc1);
}

void solve(){

    cin >> n;

    for(int i = 0; i < n; i++){
        P[i] = i;
    }
    shuffle(P, P+n, rng);
    

    string s(n, '0');
    val = ask(s);

    if (val == n){
        cout << "! " << s << endl;
        return;
    }

    int cnt1 = n - val;
    search(0, n-1, cnt1);

    cout << "! ";
    for(int i =0; i < n; i++) cout << ans[i];
    cout << endl;
}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
   // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
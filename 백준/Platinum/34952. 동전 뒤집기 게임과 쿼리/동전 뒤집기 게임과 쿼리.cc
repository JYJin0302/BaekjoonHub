#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int n;

int fw[505050];
void update(int ix, int val){
    while(ix <= n + 10){
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

    cin >> n;

    string s;
    cin >> s;

    s = '_' + s;

    for(int i = 1; i <= n; i++){
        if (s[i] != s[i-1]){
            update(i, 1);
        }
    }

    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        
        if (t == 1){
            int i;
            cin >> i;

            // rollback
            if (s[i] != s[i-1]) update(i, -1);
            if (i + 1 <= n && s[i] != s[i+1]) update(i + 1, -1);

            s[i] = char('H' + 'T' - s[i]);
            
            if (s[i] != s[i-1]) update(i, 1);
            if (i + 1 <= n && s[i] != s[i+1]) update(i + 1, 1);
        }
        else{
            int a, b;
            cin >> a >> b;
            

            if (s[a] == s[b]){
                if (s[a] == 'H') cout << "First\n";
                else cout << "Second\n";
            }
            else{
                int cnt = getS(b) - getS(a);
                if ((cnt/2) & 1) cout << "First\n";
                else cout << "Second\n";
            }
        }
    }



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
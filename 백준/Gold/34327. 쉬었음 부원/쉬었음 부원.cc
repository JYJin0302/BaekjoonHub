#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int P[4];
int C[20][5];

int ord1[20];
int ord2[20];

void solve() {

    int n;
    cin >> n;

    vector<int> A(n);
    for(auto& i : A) cin >> i;
    for(int i =0 ;i < n; i++){
        ord1[A[i]] = i;
    }

    cin >> P[1] >> P[2] >> P[3];

    for(int i =1; i <= n; i++){
        for(int j =0 ; j <= 3; j++) cin >> C[i][j];
    }

    vector<int> X(4);
    for(auto& i: X) cin >> i;
    for(int i =0 ;i < 4; i++){
        ord2[X[i]] = i;
    }


    int maxVal = -1000;
    int ansCnt = 1000;
    for(int state = 0; state < (1 << 2*n); state++){

        vector<int> rec(n+1);
        int ts = state;
        for(int i = 0; i < n;i++){
            rec[i+1] = ts % 4;
            ts >>= 2;
        }

        vector<int> pcnt(5);
        int cost = 0;
        for(int i =1 ; i <= n; i++){
            cost += C[i][rec[i]];
            pcnt[rec[i]]++;
        }
        if (cost < maxVal) continue;
        bool ok = 1;
        for(int j = 1; j < 4; j++){
            if (pcnt[j] > P[j]) ok = 0;
        }
        if (!ok) continue;

        // cout << "Go state: ";
        // for(int i = 0; i < n; i++) cout << rec[i+1] << ' ';
        // cout << endl;

        vector<array<int, 3>> O;
        for(int i = 1; i <= n; i++){
            O.push_back({ord2[rec[i]], ord1[i], i});
        }
        sort(all(O));
        // cout << "NEW order: ";
        // for(auto f: O) cout << f[2] << ' ';
        // cout << '\n';


        vector<int> mv(n);
        for(int i = 0; i < n; i++) mv[ord1[O[i][2]]] = i;

        // for(auto f : mv) cout << f<< ' ';
        // cout << '\n';

        vector<bool> chk(n);
        int cnt2 = 0;
        for(int i = 0; i < n; i++){
            if (chk[i]) continue;

            int sz = 0;
            int ti = i;
            while(1){
                chk[ti] = 1;
                ti = mv[ti];
                sz++;
                if (ti == i) break;
            }

            cnt2 += sz-1;
        }

        if (maxVal < cost){
            maxVal = cost;
            ansCnt = cnt2;
        }
        else if (maxVal == cost){
            ansCnt = min(ansCnt, cnt2);
        }

        //cout << cost << ' '<< cnt2 << '\n';
    }

    cout << ansCnt << '\n';

}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
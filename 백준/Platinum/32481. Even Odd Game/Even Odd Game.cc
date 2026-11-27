#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


int dp[303][303][2][2][2];
int mv[303][303][2][2][2];

int getDp(int cntO, int cntE, int cntR, int num, int turn){
    int& ret = dp[cntO][cntE][cntR][num][turn];
    if (ret != -1) return ret;

    if (cntO + cntE == 0){
        return ret = (turn == num ? 0 : 1);
    }

    if (cntO && !getDp(cntO-1, cntE, cntR, num^1, turn^1)){
        mv[cntO][cntE][cntR][num][turn] = 1;
        return ret = 1;
    }
    if (cntE && !getDp(cntO, cntE - 1, cntR, 0, turn^1)){
        mv[cntO][cntE][cntR][num][turn] = 2;
        return ret = 1;
    }
    if (cntR &&  !getDp(cntO, cntE, cntR - 1, num, turn^1)){
        mv[cntO][cntE][cntR][num][turn] = 3;
        return ret = 1;
    }
    return ret = 0;
}


void solve(){
    
    memset(dp, -1, sizeof dp);

    int n;
    cin >> n;


    vector<pair<char, int>> O, E, R;

    int cntE = 0, cntO = 0, cntR = 0;
    for(int i =0 ; i< n; i++){
        char c;
        cin >> c;
        int x;
        cin >> x;


        if (c == '+'){
            if(x & 1) {
                cntO++;
                O.push_back(mp(c, x));
            }
            else {
                cntR++;
                R.push_back(mp(c, x));
            }
        }
        else{
            if (x & 1) {
                cntR++;
                R.push_back(mp(c, x));
            }
            else {
                cntE++;
                E.push_back(mp(c, x));
            }
        }
    }

    int nn ;
    cin >> nn;
    nn &= 1;

    int s = getDp(cntO, cntE, cntR & 1, nn, 0);
    int t = 0, ss = 0;
    if (s){
        cout << "me" << endl;
        t = 0;
        ss = 0;
    }
    else {
        cout << "you" << endl;
        t = 1;
        ss = 1;
    }

    for(int i =0 ;i < n; i++){
        cntO = (int)O.size();
        cntE = (int)E.size();
        cntR = (int)R.size() & 1;
        if (t == 0){
            // my turn
            int g = getDp(cntO, cntE, cntR, nn, ss);    
            assert(g);
            int nxt = mv[cntO][cntE][cntR][nn][ss];

            if (nxt == 0 || nxt == 3){
                auto[a,b] = R.back();
                R.pop_back();
                cout << a << ' ' << b << endl;
            }
            else if (nxt == 1){
                auto[a,b] = O.back();
                O.pop_back();
                nn ^= 1;
                cout << a<< ' '<< b << endl;
            }   
            else{
                auto[a,b] = E.back();
                E.pop_back();
                nn = 0;
                cout << a<< ' '<< b << endl;
            }
        }
        else{
            char c;
            cin >> c;
            int x;
            cin >> x;
            if (c == '+'){
                nn = (nn + x) & 1;
                if (x & 1){
                    auto iter = O.begin();
                    while(iter != O.end() && *iter != mp(c, x)) iter++;
                    O.erase(iter);
                }
                else{
                    auto iter = R.begin();
                    while(iter != R.end() && *iter != mp(c, x)) iter++;
                    R.erase(iter);
                }

            }
            else{
                nn = (nn * x) & 1;
                if (x & 1){
                    auto iter = R.begin();
                    while(iter != R.end() && *iter != mp(c, x)) iter++;
                    R.erase(iter);
                }
                else{
                    auto iter = E.begin();
                    while(iter != E.end() && *iter != mp(c, x)) iter++;
                    E.erase(iter);
                }
            }
        }

        // cout << "State\n";
        // for(auto f: O) cout << f.x << ' '<< f.y << " | ";
        // cout << '\n';
        
        // for(auto f: E) cout << f.x << ' '<< f.y << " | ";
        // cout << '\n';
        
        // for(auto f: R) cout << f.x << ' '<< f.y << " | ";
        // cout << '\n';
        // cout << endl;
        t ^= 1;
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

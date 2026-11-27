#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int A[3][1010];
vector<pair<int, int>> ans;


int tar[5];

void addAns(int l, int r){
    int ti = 0;
    while(ti < 3 && A[ti][l] == -1) ti++;

    assert(ti != 3);

    int val = A[ti][l];
    A[ti][l] = -1;

    ti = 0;
    while(ti < 3 && A[ti][r] == -1) ti++;
    
    assert(ti != 0);
    A[ti-1][r] = val;

    ans.push_back(mp(l, r));
}

void solve(){
    
    int n;
    cin >> n;
    for(int i = 0 ;i < 3; i++){
        for(int j = 1; j <= n; j++){
            cin >> A[i][j];
        }
    }
    vector<bool> done(n+10);
    for(int i = 1; i <= n; i++){
        if (A[0][i] == A[1][i] && A[0][i] == A[2][i]) done[i] = 1;
    }

    int R = n+1;
    for(int i =0 ;i < 3; i++) A[i][R] = -1;

    while(1){
        int ix = 1;
        while(ix <= n+1){
            if (ix == R) ix++;
            else{
                bool ok = 1;
                for(int j = 0; j < 3; j++){
                    if (A[j][ix] != A[0][ix]) ok = 0;
                }
                if (ok) {
                    ix++;
                }
                else break;
            }
        }

        if(ix > n+1) break;

        vector<pair<int, int>> pos;
        int cur = A[0][ix];
        for(int i = 0; i < 3; i++){
            for(int j = ix; j <= n+1; j++){
                if (A[i][j] == cur) pos.push_back(mp(j, i));
            }
        }
        sort(all(pos));

        if(pos[0].x == pos[1].x){
            int y1 = pos[1].y;
            int y2 = pos[2].y;

            int x1 = pos[0].x;
            int x2 = pos[2].x;
            if(y1 == 2 && y2 == 2){
                addAns(x2, R);
                addAns(x2, R);
                addAns(x1, x2);
                addAns(x1, R);
                addAns(x1, x2);
                R = x1;
            }
            else if (y1 == 2 && y2 == 1){
                addAns(x1, R);
                addAns(x2, x1);
                addAns(x2, R);
                addAns(x1, x2);
                addAns(x1, x2);
                addAns(x1, R);
                R = x1;
            }
            else if(y1 == 2 && y2 == 0){
                addAns(x1, R);
                addAns(x2, R);
                addAns(x1, x2);
                addAns(x1, R);
                R = x1;
            }
            else if(y1 == 1 && y2 == 2){
                addAns(x1, R);
                addAns(x1, R);
                addAns(x2, x1);
                addAns(x2, x1);
                addAns(x2, R);
                R = x2;
            }
            else if (y1== 1 && y2== 1){
                addAns(x1, R);
                addAns(x1, R);
                addAns(x2, x1);
                addAns(x2, R);
                addAns(x2, x1);
                R = x2;
            }
            else{
                // y1 == 1 && y2 == 0
                addAns(x1, R);
                addAns(x1, R);
                addAns(x2, R);
                addAns(x1, x2);
                R = x1;
            }
        }
        else if (pos[1].x == pos[2].x){
            int y1 = pos[1].y;
            int y2 = pos[2].y;

            int x1 = pos[0].x;
            int x2 = pos[2].x;

            if (y1 == 0 && y2 == 1){
                
                addAns(x1, R);
                addAns(x2, R);
                addAns(x2, R);
                addAns(x2, x1);
                R = x2;
            }
            else if (y1 == 0 && y2 == 2){
                addAns(x1, R);
                addAns(x2, R);
                addAns(x2, x1);
                addAns(x2, R);
                R = x2;
            }
            else{
                // y1 == 1 && y2 == 2
                addAns(x1, R);
                addAns(x2, x1);
                addAns(x2, R);
                addAns(x2, R);
                R = x2;
            }
        }
        else{
            // three            
            int y1 = pos[1].y;
            int y2 = pos[2].y;

            if(y1 > y2){
                swap(y1, y2);
                swap(pos[1], pos[2]);
            }

            int x1 = pos[0].x;
            int x2 = pos[1].x;
            int x3 = pos[2].x;

            if(y1 == 0 && y2 == 0){
                addAns(x1, R);
                addAns(x2, R);
                addAns(x3, R);
                addAns(x3, x1);
                addAns(x3, x2);
                R = x3;
            }
            else if(y1== 0 && y2 == 1){
                addAns(x1, R);
                addAns(x2, R);
                addAns(x3, x1);
                addAns(x3, R);
                addAns(x3, x2);
                R = x3;

            }
            else if (y1 == 0 && y2 == 2){
                addAns(x1, R);
                addAns(x2, R);
                addAns(x3, x1);
                addAns(x3, x2);
                addAns(x3, R);
                R = x3;
            }
            else if(y1 == 1 && y2 == 1){
                addAns(x1, R);
                addAns(x2, x1);
                addAns(x2, R);
                addAns(x3, x2);
                addAns(x3, R);
                addAns(x3, x2);
                R = x3;
            }
            else if(y1 == 1 && y2 == 2){
                addAns(x1, R);
                addAns(x2, x1);
                addAns(x2, R);
                addAns(x3, x2);
                addAns(x3, x2);
                addAns(x3, R);
                R = x3;
            }
            else{
                // y1 == 2 && y2 == 2
                addAns(x2, R);
                addAns(x2, R);
                addAns(x1, x2);
                addAns(x3, x1);
                addAns(x3, R);
                addAns(x3, x2);
                R = x3;
            }
        }

        // cout << "State: " << R << "\n";
        // for(int i = 0 ;i < 3; i++){
        //     for(int j = 1; j <= n+1; j++){
        //         cout << A[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        // cout << endl;
    }

    if (R != n+1){
        addAns(n+1, R);
        addAns(n+1, R);
        addAns(n+1, R);
    }

    cout << ans.size() << '\n';
    for(auto[a,b]: ans) cout << a<< ' '<< b << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
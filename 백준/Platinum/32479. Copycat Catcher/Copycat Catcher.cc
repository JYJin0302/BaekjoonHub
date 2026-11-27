#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int enc(char c){
    if (c >= 'a' && c <= 'z') return c - 'a';
    return c-'A' + 26;
}

const int mod = 1e9 + 7;
const int p = 1000003;




void setup(int n, vector<pair<int, int>>& r){
    r.clear();
    for(int i =0 ; i< n; i++){
        string s;
        cin >> s;

        if (isalpha(s[0]) && (int)s.size() == 1){
            // variable
            r.push_back(mp(enc(s[0]), 1));
        }
        else{
            ll val = 0;
            for(auto f : s){
                val= val * p + f;
                val %= mod;
            }
            r.push_back(mp(val, 0));
        }
    }
}

int pre[52][2020];

vector<int> getFail(vector<pair<int, int>> A){
    int n = (int)A.size();
    for(int j =0 ; j< 52; j++){
        for(int i =0; i < n;i++){
            pre[j][i] = -1;
        }
    }
    for(int i =0 ; i< n; i++){
        if (i){
            for(int j =0;j <52;j++){
                pre[j][i] = pre[j][i-1];
            }
        }
        if (A[i].y == 1){
            pre[A[i].x][i] = i;
        }
    }
    vector<int> fail(n);
    for(int i = 1; i < n;i++){
        int j =fail[i-1];
        while(j){
            if (A[j].y == 0 && A[i].y == 0 && A[j].x == A[i].x) break;
            if (A[j].y != A[i].y || A[j].y == 0) j = fail[j-1];
            else{
                // test variable
                // 0 ~ j 애서 j의 순서 vs i-j~i 에서 i의 순서

                int pos1 = pre[A[j].x][j-1];
                int pos2 = pre[A[i].x][i-1];

                bool match = 0;
                if (pos1 == -1 && pos2 < i-j) match = 1;
                if(pos1 != -1 && j-pos1 == i - pos2) match = 1;

                if(match) break;
                j = fail[j-1];
            }
        }

        if (j) fail[i] = j+1;
        else{
            if (A[0].y == 0 && A[i].y == 0 && A[0].x == A[i].x) fail[i] = j+1;
            if (A[0].y == 1 && A[i].y == 1) fail[i] = j+1;
        }
    }
    return fail;

}

int Pre[52][2020];
void solve(){
    
    int n;
    cin >> n;

    vector<pair<int, int>> A;
    setup(n, A);
    // for(auto[a,b]: A) cout << a<< ' ' <<b << " | ";
    // cout << '\n';
    memset(Pre, -1, sizeof Pre);
    for(int i =0 ;i < n; i++){
        if (A[i].y == 1){
            Pre[A[i].x][i] = i;
        }
        if (i){
            for(int j =0; j < 52; j++){
                Pre[j][i] = max(Pre[j][i], Pre[j][i-1]);           
            }
        }
    }

    int q;
    cin >> q;
    while(q--){
        int tn;
        cin >> tn;
        vector<pair<int, int>> B;

        setup(tn, B);

        // cout << "SETUP\n";
        // for(auto[a,b] :B) cout << a<< ' '<< b << " | ";
        // cout << '\n';

        vector<int> fail = getFail(B);
        // for(auto f: fail) cout << f << ' ' ;
        // cout << '\n';
        

        bool found = 0;
        int j = 0;
        for(int i =0 ; i< n; i++){
            //cout << "Go i : " << i << endl;;
            while(j){
                //cout << "Chcek j :" << j<< endl;
                // check match for A[i], B[j]
                if (A[i].y == 0 && B[j].y == 0 && A[i].x == B[j].x) break;
                if (A[i].y == 0 || B[j].y == 0) j = fail[j-1];
                else{

                    int pos1 = Pre[A[i].x][i-1];
                    int pos2 = pre[B[j].x][j-1];
                    //cout << "pos: " << pos1 << ' ' << pos2 << endl;
                    bool match = 0;
                    if (pos2 == -1 && pos1 < i-j) match = 1;
                    if (pos2 != -1 && i - pos1 == j - pos2) match = 1;

                    if (match) break;
                    j = fail[j-1];
                }
            }
            if (j) j++;
            else {
                if (A[i].y == 0 && B[0].y == 0 &&  A[i].x == B[0].x) j++;
                else if(A[i].y == 1 && B[0].y == 1) j++;
            }

            //cout << i << ' '<< j << endl;

            if (j == tn){
                found = 1;
                break;
            }
        }

        if (found) cout << "yes\n";
        else cout << "no\n";
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

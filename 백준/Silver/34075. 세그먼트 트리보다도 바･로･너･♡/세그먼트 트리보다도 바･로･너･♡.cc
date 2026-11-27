#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

int pw = 0;
bool cmp(pair<int, string>& p1, pair<int, string>& p2){
    int d1 = abs(pw - p1.x);
    int d2 =abs(pw - p2.x);
    if (d1 != d2) return d1 < d2;
    return p1.y < p2.y;
}

void solve(){

    int n;
    cin >> n;

    vector<pair<int ,string>> A;
    for(int i = 0; i < n; i++){
        string s;
        int x;
        cin >> s >> x;
        A.push_back(mp(x, s));
    }
    sort(all(A));

    int m;
    cin >> m;

    map<string, int> S;
    for(int i = 0 ;i < m; i++){
        string s;
        cin >> s;
        int x;
        cin >> x;
        S[s] = x;
    }

    int q;
    cin >> q;

    string cur = "";
    while(q--){
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;


        if (s2 == "-"){
            cur = s1;
            cout << "hai!\n";
        }
        else{
            pw = S[cur];

            sort(all(A), cmp);

            cout << A[1].y << " yori mo " << A[0].y << '\n';
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
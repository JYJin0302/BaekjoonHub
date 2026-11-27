#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int cross(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3){
    int res = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    res -= p1.y * p2.x + p2.y * p3.x + p3.y* p1.x;
    if(res) res /= abs(res);
    return res;
}

bool intersect(pair<int, int> s1, pair<int, int> s2, pair<int, int> e1, pair<int, int> e2){
    if (s1 == e1 || s1 == e2 || s2 == e1 || s2 == e2) return 0;
    if (cross(s1, s2, e1) * cross(s1, s2, e2) < 0 && cross(e1, e2, s1 ) * cross(e1, e2, s2) < 0) return 1;
    return 0;
}


vector<int> lst[303];

void solve(){
    
    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for(auto&[a,b]: A) cin >> a >> b;

    vector<pair<int, int>> edg;
    // count edge 
    for(int i =0 ;i < n; i++){
        for(int j = i+1; j < n; j++){
            bool ok = 1;
            for(auto[a,b] :edg){
                if(intersect(A[a], A[b], A[i], A[j])) {
                    ok = 0;
                    break;
                }
            }
            if (ok) edg.push_back(mp(i ,j));
        }
    }

    int cc = (int)edg.size();
    int turn = 0;
    if (cc & 1){
        turn = 1;
        cout << 1 << endl;
    }
    else cout << 2 << endl;

    edg.clear();
    
    for(int i =0 ; i< n; i++){
        for(int j = i+1; j < n; j++) lst[i].push_back(j);
    }

    int tc = 0;
    while(1){
        if (turn){
            pair<int, int> res = mp(-1, -1);
            for(int i =0 ;i < n; i++){
                
                while(!lst[i].empty()){
                    auto f = lst[i].back();
                    // try i, f

                    bool ok = 1;
                    for(auto[a,b]: edg){
                        if (intersect(A[a], A[b], A[i], A[f])){
                            ok = 0;
                            break;
                        }
                    }
                    if (ok){
                        res = mp(i, f);
                        break;
                    }
                    else{
                        lst[i].pop_back();
                    }
                }
                if (res.x != -1) break;
            }

            assert(res.x != -1);

            cout << res.x +1 << ' '<< res.y + 1 << endl;
            edg.push_back(res);
            lst[res.x].erase(lower_bound(all(lst[res.x]), res.y));
        }
        else{

            int a, b;
            cin >> a>> b;
            if (a > b) swap(a, b);

            if (a + b == 0){
                return;
            }

            a--, b--;
            edg.push_back(mp(a, b));
            lst[a].erase(lower_bound(all(lst[a]), b));
        }

        turn ^= 1;
        tc++;

    }
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

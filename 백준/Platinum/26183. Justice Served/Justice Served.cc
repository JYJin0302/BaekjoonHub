#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

bool cmp(pair<pair<int, int>, int> p1, pair<pair<int, int>, int> p2){
    if(p1.x.x != p2.x.x) return p1.x.x < p2.x.x;
    return p1.x.y > p2.x.y;
}

int maxN = 400040;
int fw[404040];
void update(int ix, int val){
    while(ix <= maxN){
        fw[ix] = max(fw[ix], val);
        ix += ix & -ix;
    }
}

int getM(int ix){
    int ret = 0;
    while(ix){
        ret = max(ret, fw[ix]);
        ix -= ix & -ix;
    }
    return ret;
}

void solve(){
    
    int n;
    cin >> n;
    
    vector<pair<pair<int, int>, int>> A;
    vector<int> num;
    for(int i =0; i < n; i++){
        int a, b;
        cin >> a>> b;
        A.push_back(mp(mp(a, a+b), i));
        num.push_back(a);
        num.push_back(a+b);
    }

    sort(all(num));
    num.erase(unique(all(num)), num.end());

    for(auto&[a,b]:A){
        a.x = lower_bound(all(num), a.x) - num.begin() + 1;
        a.y = lower_bound(all(num), a.y) - num.begin() + 1;
    }
    sort(all(A), cmp);

    vector<int> ans(n);

    for(auto[a,b]: A){
        int ix = (int)num.size() - a.y + 1;
        //cout << "GO : "<< a.x << ' '<< a.y << " | " << b << ' '<< ix << endl;
        int res = getM(ix);
        ans[b] = res + 1;
        update(ix, ans[b]);
    }

    for(auto f: ans) cout <<f -1<< ' ';
    cout << '\n';


}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }   
    return 0;
}


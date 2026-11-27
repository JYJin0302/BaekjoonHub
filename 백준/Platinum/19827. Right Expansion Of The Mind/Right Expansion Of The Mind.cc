#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()


void solve(){
    int n;
    cin >> n;

    vector<tuple<string, int, int>> A;
    for(int i =0 ; i < n; i++){
        string s1 ,s2;
        cin >> s1 >> s2;

        int v1 = 0, v2 = 0;
        for(auto f :s2){
            v2 |= (1 << (f - 'a'));
        }

        while(!s1.empty()){
            int v =s1.back() - 'a';
            if (v2 & (1 << v)) s1.pop_back();
            else break;
        }

        //cout << s1 << " | " << v2 << '\n';
        A.push_back({s1, v2, i});
    }
    sort(all(A));

    vector<vector<int>> ans;

    vector<int> cur;
    cur.push_back(get<2>(A[0]));
    for(int i = 1; i < n; i++){
        if(get<0>(A[i-1]) == get<0>(A[i]) && get<1>(A[i-1]) == get<1>(A[i])){
            cur.push_back(get<2>(A[i]));
        }
        else{
            ans.push_back(cur);
            cur.clear();
            cur.push_back(get<2>(A[i]));
        }
    }
    ans.push_back(cur);

    cout << (int)ans.size() << '\n';
    for(auto f : ans){
        cout << (int)f.size() << ' ';
        for(auto d : f) cout << d+1 << ' ';
        cout << '\n';
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

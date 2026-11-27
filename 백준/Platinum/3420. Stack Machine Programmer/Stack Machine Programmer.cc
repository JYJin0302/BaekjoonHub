#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

void solve(){
    int n;
    cin >> n;
    while(n){

        vector<pair<string ,int>> ans;

        vector<pair<int, int>> A(n);
        for(auto&[a,b] : A) {
            cin >> a >> b;
            a++;
        }
        sort(all(A));
        
        ans.push_back(mp("NUM", 1));
        ans.push_back(mp("ADD", 0));
        for(int i = 0; i < n ;i++){
            ans.push_back(mp("DUP", 0));
            for(int j = n-1; j > i ;j--){
                ans.push_back(mp("NUM", A[j].x));
                ans.push_back(mp("MOD", 0));
            }
            ans.push_back(mp("NUM", A[i].x));
            ans.push_back(mp("DIV", 0));

            ans.push_back(mp("NUM", A[i].y));
            ans.push_back(mp("MUL", 0));
            ans.push_back(mp("SWP", 0));
        }

        ans.push_back(mp("NUM", 0));
        ans.push_back(mp("MUL", 0));

        for(int i= 0 ; i < n;i++){
            ans.push_back(mp("ADD", 0));
        }

        for(auto[a,b]: ans){
            if (a == "NUM") cout << a << ' '<< b<< '\n';
            else cout << a<< '\n';
        }
        cout << "END\n";   

        cin >> n;
        if (n) cout << '\n';
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}

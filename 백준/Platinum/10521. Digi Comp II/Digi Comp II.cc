
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int L[505050], R[505050];
int topo[505050];
ll val[505050];

void solve(){

    ll n, m;
    cin >> n >> m;

    vector<char> A(m+1);
    for(int i= 1; i <= m; i++){
        cin >>A[i];

        cin >>L[i] >> R[i];
        topo[L[i]]++;
        topo[R[i]]++;
    }

    val[1] = n;

    queue<int> q;
    for(int i =1 ; i <= m; i++) if (topo[i] == 0) q.push(i);
    
    while(!q.empty()){

        int a = q.front();
        q.pop();

//        cout << a<< ' ';
//        for(int f= 1; f <= m; f++) cout << val[f] <<' ';
//        cout <<'\n';

        if(a == 0) continue;

        if(A[a] == 'L'){
            val[L[a]] += (val[a]+1)/2;
            val[R[a]] += val[a] / 2;
        }
        else{
            val[R[a]] += (val[a]+1)/2;
            val[L[a]] += val[a] / 2;
        }
        topo[L[a]]--;
        if(topo[L[a]] == 0) q.push(L[a]);
        topo[R[a]]--;
        if (topo[R[a]] == 0)q.push(R[a]);
    }

    for(int i = 1; i <= m; i++){

        val[i] %= 2;

        if(val[i] == 1) cout << char('L' +'R' - A[i]);
        else cout<< A[i];
    }
    cout <<'\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

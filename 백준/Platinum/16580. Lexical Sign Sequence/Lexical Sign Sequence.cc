
#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >>k;

    vector<int>A(n), sA(n);
    for(auto&i :A) cin >>i;

    for(int i = 0; i <n; i++)if (A[i]==-1) sA[i] = 1;
    for(int i = 1; i <n; i++)sA[i] += sA[i-1];

    bool ok1 = 1;
    vector<tuple<int, int, int>> q;
    for(int i = 0; i <k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        c = (c + b-a + 2) / 2;
        c = b-a+1-c;

        int tcnt = sA[b] - sA[a] + (A[a] == -1);
        if(tcnt > c) ok1 = 0;
        //cout << "ADD:"<<a <<' ' <<b <<' ' << c-tcnt <<'\n';
        q.push_back({a, b, c - tcnt});
    }
    if(!ok1){
        cout <<"Impossible";
        return 0;
    }

    sort(q.begin(), q.end());

    //for(auto i :q) cout <<i.l <<' ' <<i.r <<' ' <<i.k <<'\n';

    bool ok = 1;
    priority_queue<tuple<int, int, int>> pq;

    int ix = 0, cnt0 = 0;
    for(int i = 0; i <n; i++){

        while(ix < k){
            auto&[a, b, c] = q[ix];
            if (a == i){
                pq.push({-cnt0 - c, a, b});
                ix++;
            }
            else break;
        }

        while(!pq.empty()){

            auto&[a,b ,c]=pq.top();

            if(c < i) pq.pop();
            else break;
        }
        if (A[i] != 0)continue;

        bool able = 0;
        if (pq.empty() || -get<0>(pq.top()) > cnt0) able = 1;

        if (able){
            A[i] = -1;
            cnt0++;
        }
        else A[i] = 1;
    }

    for(int i = 0; i <n; i++)cout <<A[i] <<' ';

    return 0;
}

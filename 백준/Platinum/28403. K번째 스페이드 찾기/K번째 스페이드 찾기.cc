#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
using ll = long long;


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >>n;

    string s;
    cin >>s;

    vector<int> A(n+1);
    for(int i = 0; i < n; i++){
        if (s[i] == 'S') A[i]++;
    }

    vector<int> sA(n+1);
    sA[0] = A[0];

    for(int i = 1; i <= n; i++) sA[i] = sA[i-1] +A[i];

    vector<int> nxt(n+10, n);
    nxt[n-1] = n-1;
    if(A[n-1] == 0) nxt[n-1] = n;

    for(int i = n-2; i >= 0; i--){
        if(A[i] == 1) nxt[i] = i;
        else nxt[i] = nxt[i+1];
    }

   // for(int i = 0 ; i<n ;i++)cout <<nxt[i] <<' ';
   //cout <<'\n';

    for(int i = 0; i < n; i++){
        // simulation
       // cout <<"Sim: "<< i+1 <<'\n';
        int ans = 1;
        int currIdx = i+1;
        int currCnt = sA[i];
        while(currIdx < n && currCnt != i+1){
            //cout << "Curr:" << ans <<' ' <<currIdx <<' ' <<currCnt <<'\n';
            int ndx = nxt[currIdx];
            int diff = i+1 - currCnt;

            if(n-currIdx < diff) break;
            int d = 0;
            if (ndx == n) {
                    ans += (n - currIdx) /diff;
                    break;
            }
            else d = (ndx - currIdx + 1 +diff-1) / diff;

            int newIdx = currIdx + diff*d;
            if (newIdx > n){
                ans += max(0, d-1);
            }
            else ans += d;
            //cout <<"NXT:"<<ndx <<' ' <<d <<'\n';

            currIdx = newIdx;
            currCnt = sA[currIdx-1];
            if (ndx == n) break;
        }

        cout <<ans <<' ';
    }


}

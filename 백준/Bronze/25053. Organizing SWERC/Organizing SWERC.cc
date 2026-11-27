
#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n;
    cin >>n;

    vector<int>A(11);
    for(int i = 0; i <n; i++){
        int a, b;
        cin >>a >>b;
        A[b] = max(A[b], a);
    }

    for(int i = 1; i <=10; i++) {
        if(A[i] == 0){
            cout <<"MOREPROBLEMS\n";
            return;
        }
    }

    int tot = 0;
    for(int i = 1; i <= 10; i++) tot += A[i];
    cout <<tot << '\n';


}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);


    int t;
    cin >>t;
    while(t--){

        solve();
    }
}

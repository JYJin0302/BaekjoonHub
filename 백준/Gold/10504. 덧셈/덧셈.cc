
#include <bits/stdc++.h>
using namespace std;

void solve(){

int n;
cin >>n;
    vector<int> ans;
    for(int i = 2; i * i <= 2*n; i++){
        if (2*n %i == 0) {
                if (i % 2 == 0){
            if (n %i == 0)continue;

            int a = n/i;
            int b= a + i/2;
            a -= i/2-1;

            cout << n << " = ";
            for(int j = a; j <= b; j++) {
                    cout << j;
                    if(j != b) cout << " + ";
            }
            cout <<'\n';
            return;
        }
        else{

            int a = n/i - i/2;
            int b = n/i + i/2;
            cout << n << " = ";
            for(int j = a; j <= b; j++) {
                    cout << j;
                    if(j != b) cout << " + ";
            }
            cout <<'\n';
            return;
        }
        }
    }

    cout << "IMPOSSIBLE\n";
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

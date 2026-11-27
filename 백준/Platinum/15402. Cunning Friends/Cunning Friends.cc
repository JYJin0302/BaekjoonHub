#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin>> x;
        if (x == 1) cnt1++;
        else if (x == 2) cnt2++;
        else cnt3++;
    }

    if (n == 1) cout << "Win";
    else if (n == 2){
        if (cnt1 != 0) cout << "Win";
        else cout << "Lose";
    }
    else if(cnt1 == n){
        if(n % 3 != 0) cout << "Win";
        else cout << "Lose";
    }
    else if (cnt2 == 2 || (cnt2 == 1 && cnt3 == 1)){
        if(n%3 == 2) cout << "Lose";
        else cout << "Win";
    }
    else if (cnt3 + cnt2 == 1){
        cout << "Win";
    }
    else cout << "Lose";


    return 0;
}
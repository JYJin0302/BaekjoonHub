#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()



void solve(){
    
    int a, b;
    cin >> a >> b;

    vector<int> l1, l2, l3;
    for(int i = a; i <= b; i++){
        string s;
        cin >> s;

        if (s == "Fizz") l1.push_back(i);
        else if (s == "Buzz") l2.push_back(i);
        else if (s== "FizzBuzz") {
            l1.push_back(i);
            l2.push_back(i);
        }
        else {
            l3.push_back(i);
        }
    }

    int a1, b1;
    if (l1.empty()) a1 = 1000000;
    else if((int)l1.size() == 1) a1 = l1[0];
    else a1 = l1[1] - l1[0];

    if (l2.empty()) b1 = 1000000;
    else if ((int)l2.size() == 1) b1 = l2[0];
    else b1 = l2[1] - l2[0];

    cout << a1 << ' '<< b1 << '\n';
    
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


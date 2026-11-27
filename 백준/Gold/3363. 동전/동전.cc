#include <bits/stdc++.h>
using namespace std;

struct Nset{
    int a, b, c, d;
};
tuple<Nset, char, Nset> inp[3];

int cnt = 0; string ans = "";
void test(int num, bool l){
    vector<int> val(13);
    val[num] = 2*l - 1;
    
    bool ok = 1;
    for(int i = 0; i <3 ; i++){
        
        Nset A, B;
        char C;
        tie(A, C, B) = inp[i];
        
        int v1 = 0, v2 = 0;
        v1 += val[A.a] + val[A.b] + val[A.c] + val[A.d];
        v2 += val[B.a] + val[B.b] + val[B.c] + val[B.d];
        
        bool tt = (v1 > v2 && C == '>') || (v1 < v2 && C == '<') || (v1 == v2 && C == '=');
        
        ok = ok && tt;
    }
    
    if (ok) {
        cnt++;
        ans = char(num + '0');
        ans += (l ? "+" : "-");
    }
}

int main(){
    
    Nset A, B;
    char C;
    
    for(int i = 0; i < 3; i++){
        cin >> A.a >> A.b >> A.c >> A.d;
        cin >> C;
        cin >> B.a >> B.b >> B.c >> B.d;
        inp[i] = {A, C, B};
    }
    
    for(int i = 1; i <=12; i++){
        test(i, 0);
        test(i, 1);
    }
    if (cnt == 0) cout << "impossible";
    else if (cnt > 1) cout << "indefinite";
    else cout << ans;
}
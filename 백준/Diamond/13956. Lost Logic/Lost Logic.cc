
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int A[3][55];

bool isSame(int i, int j){
    int res = A[0][i] ^ A[0][j];
    if(res != A[1][i] ^ A[1][j])return 0;
    if(res != A[2][i] ^ A[2][j])return 0;
    return 1;
}

bool isDistinct(int i, int j){

    vector<int>cnt(4);
    for(int x = 0; x < 3; x++){
        cnt[A[x][i]*2 +A[x][j]]++;
    }

    for(int i = 0; i < 4; i++){
        if(cnt[i] >1) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >>n;

    for(int i = 0; i< 3; i++){
        for(int j = 1; j <= n; j++){
            cin >>A[i][j];
        }
    }

    vector<int> s1, s2, s3, s4;
    bool ok = 1;
    for(int i =1 ; i <= n; i++){
        if (A[0][i] == A[1][i] &&A[1][i] == A[2][i]){
            if (A[0][i] == 1) s3.push_back(i);
            else s4.push_back(i);
        }
        else{
            if (s1.empty() || isSame(s1[0], i)) s1.push_back(i);
            else if(s2.empty() || isSame(s2[0], i)) s2.push_back(i);
            else ok = 0;
        }
    }

    int tn = s1.size(), tm = s2.size();

    for(int i = 0; i < tn; i++){
        for(int j = 0; j < tn; j++){
            if (!isSame(s1[i], s1[j])) ok = 0;
        }
    }
    for(int i = 0; i < tm; i++){
        for(int j = 0; j < tm; j++){
            if (!isSame(s2[i], s2[j])) ok = 0;
        }
    }

    for(int i = 0; i <tn; i++){
        for(int j = 0; j <tm; j++){
            if(!isDistinct(s1[i] ,s2[j])) ok = 0;
        }
    }

    if (!ok){
        cout <<-1;
        return 0;
    }

    int n1 = s3.size();
    int n2 = s4.size();
    if(s1.empty()){

        cout <<n1 +n2 <<'\n';
        for(int i = 0; i <n1; i++){
            cout << "!x" << s3[i] << " -> x" << s3[i]<<'\n';
        }
        for(int i = 0; i <n2; i++){
            cout << "x" << s4[i] << " -> !x" << s4[i]<<'\n';
        }
        return 0;
    }
    int idx = 0;
    if(A[0][s1[0]] == A[1][s1[0]]) idx = 2;
    if(A[1][s1[0]] == A[2][s1[0]]) idx = 0;
    if(A[0][s1[0]] == A[2][s1[0]]) idx = 1;

    vector<pair<int, int>>ans;

    for(int i = 0;i < tn; i++){
        int ni = (i+ 1)%tn;
        int a= s1[i], b = s1[ni];

        if (A[idx][a] == 0) a *= -1;
        if (A[idx][b] == 0) b *= -1;

        ans.push_back({a, b});
    }

    for(int i = 0;i < tm; i++){
        int ni = (i+ 1)%tm;
        int a = s2[i], b = s2[ni];

        if (A[idx][a] == 0) a *= -1;
        if (A[idx][b] == 0) b *= -1;

        ans.push_back({a, b});
    }

    int ta = s1[0], tb = s2[0];
    if (A[idx][ta] == 0) ta *= -1;
    if (A[idx][tb] == 0)tb*=-1;
    ans.push_back({ta, tb});


    for(int i = 0; i <n1; i++){
        ans.push_back({-s3[i], s3[i]});
       // cout << "!x" << s3[i] << " -> x" << s3[i]<<'\n';
    }
    for(int i = 0; i <n2; i++){
        ans.push_back({s4[i], -s4[i]});
       // cout << "x" << s4[i] << " -> !x" << s4[i]<<'\n';
    }

    cout << ans.size()<<'\n';

    for(auto i :ans){
        int a, b;
        tie(a,b) = i;

        if (a <0){
            cout <<"!";
            a *= -1;
        }
        cout << "x" << a<< " -> ";
        if (b <0 ) {
                cout <<"!";
                b*= -1;
        }
        cout <<"x"<< b <<'\n';
    }

 }

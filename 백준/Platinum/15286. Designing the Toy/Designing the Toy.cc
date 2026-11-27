

#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pi pair<int,int>
using namespace std;


bool chk(int a, int b, int c){

    vector<int>tmp = {a, b, c};
    sort(tmp.begin(), tmp.end());

    a = tmp[0];
    b = tmp[1];
    c = tmp[2];

    return (a*b >= c);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    int cx = -100, cy = -100, cz = -100;

    int a, b,c;
    cin >> a >> b >> c;

    if (!chk(a, b, c)){
        cout <<-1;
        return 0;
    }

    vector<tuple<int, int, int>> ans;

    while(a && b && c){

        if (chk(a-1, b-1, c-1)){
            ans.push_back({cx++, cy++, cz++});
            a--, b--, c--;
        }
        else break;

    }

    if(a >= b && a >= c){
        for(int i = 0; i < b; i++){
            ans.push_back({cx+i, cy, cz});
        }
        for(int i = 1; i < c; i++){
            ans.push_back({cx, cy+i, cz});
        }

        a -= b+c-1;
        for(int i= 1; i < b; i++){
            for(int j = 1; j < c; j++){
                if(a==0) break;
                ans.push_back({cx+i, cy+j, cz});
                a--;
            }
        }

    }
    else if(b >= a && b >= c){
        for(int i = 0; i < a; i++){
            ans.push_back({cx+i, cy, cz});
        }
        for(int i = 1; i < c; i++){
            ans.push_back({cx, cy, cz+i});
        }

        b -= a+c-1;
        for(int i= 1; i < a; i++){
            for(int j = 1; j < c; j++){
                if(b==0) break;
                ans.push_back({cx+i, cy, cz+j});
                b--;
            }
        }

    }
    else if(c >= a && c >= b){
        for(int i = 0; i < b; i++){
            ans.push_back({cx, cy, cz+i});
        }
        for(int i = 1; i < a; i++){
            ans.push_back({cx, cy+i, cz});
        }

        c -= b+a-1;
        for(int i= 1; i < b; i++){
            for(int j = 1; j < a; j++){
                if(c==0) break;
                ans.push_back({cx, cy+j, cz+i});
                c--;
            }
        }

    }

    cout <<ans.size()<<'\n';
    for(auto f :ans){
        cout <<get<0>(f)<<' ' <<get<1>(f)<<' ' <<get<2>(f)<<'\n';
    }


}

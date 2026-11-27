
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mp make_pair
map<pair<pair<int, int>, int>, ll> cost;

map<pair<int, int>, vector<int>> dp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n, d;
    cin >>n >>d;

    vector<int>A(d);
    for(auto& i :A)cin >>i;

    for(int i= 1 ;i < d; i++){
        cost[mp(mp(A[i-1], A[i]), 1)] = 1e13;
        cost[mp(mp(A[i-1], A[i]), 0)] = 1e13;
        cost[mp(mp(A[i], A[i-1]), 1)] = 1e13;
        cost[mp(mp(A[i], A[i-1]), 0)] = 1e13;

        int a= A[i-1], b = A[i];
        if(a >b) dp[mp(b,a)].push_back(0);
        else dp[mp(a, b)].push_back(1);
    }

    int m;
    cin >>m;
    while(m--){
        ll a, b, d;
        char c;
        cin >>a >>b >>c >>d;

        int tc= 0;
        if(c == 'R') tc = 1;

        ll tmp = cost[mp(mp(a, b), tc)];
        cost[mp(mp(a, b), tc)] = min(tmp, d);
        cost[mp(mp(a, b), 0)] = min(cost[mp(mp(a, b), 0)], d);
    }


    ll ans =0;
    for(int i= 1 ;i < d; i++){
        int a= A[i-1], b = A[i];

        ll c1, c0, c10, c01;

        vector<int> lst;
        if(a >b) swap(a, b);
        lst = dp[mp(a, b)];
        if (lst.empty())continue;
        dp[mp(a, b)].clear();

        c1 = cost[mp(mp(a, b), 0)];  // 1 :a->b , 0 : b->a
        c10 = cost[mp(mp(a, b), 1)];
        c0 = cost[mp(mp(b, a), 0)];
        c01 = cost[mp(mp(b, a), 1)];


        //cout <<a<<' ' << b<<'\n';
        //for(auto i :{c1, c0, c10, c01})cout <<i <<' ';
        //cout <<'\n';

        ll tans1 = 0, tans2 = 0, tans3= 0;
        // 0, 1       01         10
        for(auto k : lst) {
            if(k == 1) tans1 += c1;
            else tans1 += c0;
        }

        ll cnt1 = 0, cnt0 = 0;
        for(auto k : lst){
            if(k == 1) {
                if (cnt0){
                    cnt0--;
                    tans2 += c01;
                }
                else cnt1++;
            }
            else cnt0++;
        }

        ll tcx = min(cnt0, cnt1);
        tans2 += min({cnt1 * c1 + cnt0 *c0, c10 * tcx + c1*(cnt1-tcx) + c0 *(cnt0-tcx) });

        cnt1 = 0, cnt0 = 0;
        for(auto k : lst){
            if(k == 0) {
                if (cnt1){
                    cnt1--;
                    tans3 += c10;
                }
                else cnt0++;
            }
            else cnt1++;
        }

        tcx = min(cnt0, cnt1);
        tans3 += min({cnt1 * c1 + cnt0 *c0, c01 * tcx + c1*(cnt1-tcx) + c0 *(cnt0-tcx) });

        //cout <<"Curr:"<< a <<' ' <<b <<'\n';
        //cout <<tans1 <<' ' <<tans2 <<' ' <<tans3 <<'\n';
        ans += min({tans1, tans2, tans3});
    }
    cout <<ans;

 }

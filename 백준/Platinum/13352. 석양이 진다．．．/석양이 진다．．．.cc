#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define x first
#define y second
int n;vector<pair<ll,ll>>P;
bool shot(int a, int b){
    pair<ll,ll> p1,p2;
    p1=P[a],p2=P[b];
    ll dx=p2.x-p1.x;
    ll dy=p2.y-p1.y;
    ll A,B,C;
    A=dy,B=-dx;
    C=-1*(A*p1.x+B*p1.y);
    vector<pair<ll,ll>>r;
    for(auto i:P)if(A*i.x+B*i.y+C!=0)r.push_back(i);
    if(r.size()<3)return 1;
    sort(r.begin(),r.end());
    ll vx=r[1].x-r[0].x,vy=r[1].y-r[0].y;
    for(int i=2;i<r.size();i++)if((r[i].x-r[0].x)*vy!=(r[i].y-r[0].y)*vx)return 0;
    return 1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    P=vector<pair<ll,ll>>(n);
    for(auto& i:P)cin>>i.x>>i.y;
    if(shot(0,1)||shot(1,2)||shot(2,0))cout<<"success";
    else cout<<"failure";
}
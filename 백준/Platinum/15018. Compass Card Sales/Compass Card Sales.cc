#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long

#define x first
#define y second

vector<pair<int, int>> A[3];
int getIdx[100001][3][3];
// getIdx[id][rgb][lr] = idx

int n;
int currVal[100001];
bool used[100001];

int getU(int id){
    int res = 0;
    for(int i = 0; i < 3; i++){
        int px = getIdx[id][i][0];
        int nx = getIdx[id][i][1];
        int cx = getIdx[id][i][2];

        int v1 = (A[i][nx].x - A[i][cx].x + 360) %360;
        int v2 =  (A[i][cx].x - A[i][px].x+ 360)% 360;
        if (v1 > 0 && v2 >0) res += v1 + v2;
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    vector<tuple<int, int, int, int>> tinp;
    vector<int> idList;
    // lower uniqueness, higher id first
    for(int i = 0; i < n; i++){

        int r, g,b, id;
        cin >> r>>g >> b >>id;
        tinp.push_back({r, g, b, id});

        idList.push_back(id);
    }

    sort(idList.begin(), idList.end());

    for(auto i :tinp){
        int a, b, c, d;
        tie(a, b, c, d) = i;

        d = lower_bound(idList.begin(), idList.end(), d) - idList.begin();

        A[0].push_back({a, d});
        A[1].push_back({b, d});
        A[2].push_back({c, d});
    }

    for(int i = 0; i < 3; i++){
        sort(A[i].begin(), A[i].end());
    }


    for(int i = 0; i < n; i++){
        int pi = (i+n-1)%n;
        int ni = (i+1)%n;
        getIdx[A[0][i].y][0][0] = pi;
        getIdx[A[0][i].y][0][1] = ni;
        getIdx[A[0][i].y][0][2] = i;
        getIdx[A[1][i].y][1][0] = pi;
        getIdx[A[1][i].y][1][1] = ni;
        getIdx[A[1][i].y][1][2] = i;
        getIdx[A[2][i].y][2][0] = pi;
        getIdx[A[2][i].y][2][1] = ni;
        getIdx[A[2][i].y][2][2] = i;
    }

    for(int i = 0; i < n; i++){
        currVal[i] = getU(i);
    }

    priority_queue<pair<int, int>> pq;
    for(int i = 0; i <n; i++){
        pq.push({-currVal[i], i});
    }


    while(!pq.empty()){

        int a, b;
        tie(a, b) = pq.top();
        pq.pop();

        if (currVal[b] != -a || used[b]) continue;

        // erase
        cout << idList[b] << '\n';
        used[b] = 1;

        // update
        for(int i = 0; i< 3; i++){
            int px = getIdx[b][i][0];
            int nx = getIdx[b][i][1];
            int cx = getIdx[b][i][2];

            int pId = A[i][px].y;
            int nId = A[i][nx].y;

            getIdx[pId][i][1] = nx;
            getIdx[nId][i][0] = px;

            currVal[pId] = getU(pId);
            currVal[nId] = getU(nId);

            pq.push({-currVal[pId], pId});
            pq.push({-currVal[nId], nId});
        }
    }
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define all(x) x.begin(), x.end()
#define mp make_pair

const ll INF = 1e9;


ll cX, cY;
ll getAns(array<int, 4> A){
    ll xL = A[0], xR = A[1];
    ll yL = A[2], yR = A[3];

    ll offset = 0;

    ll tmpX = cX, tmpY = cY;
    if (xL <= cX && cX <= xR){
        // ok
    }
    else if (cX < xL){
        tmpX = xL;
        offset += xL - cX;
    }
    else{
        tmpX = xR;
        offset += cX - xR;
    }
    if (yL <= cY && cY <= yR){
        // ok
    }
    else if (cY < yL){
        tmpY = yL;
        offset += yL - cY;
    }
    else{
        tmpY = yR;
        offset += cY - yR;
    }

    ll ans = tmpX * tmpX + tmpY * tmpY;
    ans = floor(sqrtl(ans));
    ans += offset;
    return ans;
}

void solve(){
    
    int n, t;
    cin >> n >> t;
    cin >> cX >> cY;

    set<array<int, 4>> st;
    st.insert(array<int, 4>{0, INF, 0, INF}); // okay area

    vector<array<int, 3>> Q;
    for(int i =0 ;i  < n; i++){
        int a, b, c;
        cin >> a>> b >> c;
        Q.push_back(array<int, 3>{a, b, c});
    }

    multiset<ll> ansLst;
    ansLst.insert(getAns(*(st.begin())));

    int qi = 0;
    for(int i = 0; i < t; i++){
        while(qi < n && Q[qi][0] == i){
            // process query
            int tx = Q[qi][1], ty= Q[qi][2];
            // cout << "Processing: " << tx << ' ' << ty << endl;

            // cout << "Area set: \n";
            // for(auto f: st) cout << f[0] << ' ' << f[1] << ' ' << f[2] << ' ' << f[3] << '\n';
            // cout << "AnsList: ";
            // for(auto f: ansLst) cout << f << ' ';
            // cout << endl;

            qi++;

            array<int,4> tmp;
            tmp = {tx, -1, 0, 0};

            vector<array<int, 4>> toADD;

            auto iter = st.lower_bound(tmp);
            iter--;

            //cout << (*iter)[0] << ' ' << (*iter)[1] << ' ' << (*iter)[2] << ' ' << (*iter)[3] << endl;

            if((*iter)[0] < tx && tx < (*iter)[1]){
                if ((*iter)[2] < ty && ty < (*iter)[3]){
                    // split in two
                    ansLst.erase(ansLst.find(getAns((*iter))));

                    tmp = {(*iter)[0], tx, (*iter)[2], ty};
                    toADD.push_back(tmp);
                    tmp = {tx, (*iter)[1], ty, (*iter)[3]};
                    toADD.push_back(tmp);

                    st.erase(iter);
                }
                else if((*iter)[3] < ty){
                    ansLst.erase(ansLst.find(getAns((*iter))));
                    tmp = {(*iter)[0], tx, (*iter)[2], (*iter)[3]};
                    toADD.push_back(tmp);

                    // keep deleting
                    iter = st.erase(iter);

                    while(1){
                        if((*iter)[3] <= ty) {
                            ansLst.erase(ansLst.find(getAns(*iter)));
                            iter = st.erase(iter);
                            continue;
                        }
                        else if ((*iter)[2] > ty) break;
                        ansLst.erase(ansLst.find(getAns(*iter)));
                        tmp = {(*iter)[0], (*iter)[1], ty, (*iter)[3]};
                        toADD.push_back(tmp);
                        st.erase(iter);
                        break;
                    }
                }
                else{
                    ansLst.erase(ansLst.find(getAns((*iter))));
                    tmp = {tx, (*iter)[1], (*iter)[2], (*iter)[3]};
                    toADD.push_back(tmp);

                    // keep deleting
                    iter = st.erase(iter);
                    iter--;

                    while(1){
                        // cout << "Current processing: " ;
                       // cout << (*iter)[0] << ' ' << (*iter)[1] << ' ' << (*iter)[2] << ' ' << (*iter)[3] << endl;
                        if((*iter)[2] > ty) {
                            ansLst.erase(ansLst.find(getAns(*iter)));
                            iter = st.erase(iter);
                            iter--;
                            continue;
                        }
                        else if ((*iter)[3] < ty) break;
                        ansLst.erase(ansLst.find(getAns(*iter)));
                        tmp = {(*iter)[0], (*iter)[1], (*iter)[2], ty};
                        toADD.push_back(tmp);
                        st.erase(iter);
                        break;
                    }
                }
            }
            else{
                if ((*iter)[2] < ty && ty < (*iter)[3]){
                    ansLst.erase(ansLst.find(getAns((*iter))));

                    tmp = {(*iter)[0], (*iter)[1], (*iter)[2], ty};
                    toADD.push_back(tmp);

                    st.erase(iter);
                }
                else if((*iter)[3] < ty){
                    iter++;

                    while(1){
                        if((*iter)[3] <= ty) {
                            ansLst.erase(ansLst.find(getAns(*iter)));
                            iter = st.erase(iter);
                            continue;
                        }
                        else if ((*iter)[2] > ty) break;
                        ansLst.erase(ansLst.find(getAns(*iter)));
                        tmp = {(*iter)[0], (*iter)[1], ty, (*iter)[3]};
                        toADD.push_back(tmp);
                        st.erase(iter);
                        break;
                    }
                }
                else{
                    ansLst.erase(ansLst.find(getAns((*iter))));

                    // keep deleting
                    iter = st.erase(iter); iter--;

                    while(1){
                        if((*iter)[2] > ty) {
                            ansLst.erase(ansLst.find(getAns(*iter)));
                            iter = st.erase(iter);
                            iter--;
                            continue;
                        }
                        else if ((*iter)[3] < ty) break;
                        ansLst.erase(ansLst.find(getAns(*iter)));
                        tmp = {(*iter)[0], (*iter)[1], (*iter)[2], ty};
                        toADD.push_back(tmp);
                        st.erase(iter);
                        break;
                    }
                }
            }

            for(auto f : toADD){
                st.insert(f);
                ansLst.insert(getAns(f));
            }
        }
        
        cout << *ansLst.begin() << '\n';
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}

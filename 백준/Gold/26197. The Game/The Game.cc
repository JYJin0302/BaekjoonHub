
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define mp make_pair

vector<int> curr[4];
void solve(){

queue<int> q;
for(int i = 0; i< 98; i++) {
    int x;
    cin >> x;
    q.push(x);
}

    curr[0].push_back(1);
    curr[1].push_back(1);
    curr[2].push_back(100);
    curr[3].push_back(100);

    vector<int> deck;
    while(deck.size() <8){
        deck.push_back(q.front());
        q.pop();
    }

    while(1){

        // backward trick
        bool done = 0;
        for(int i = 0; i < deck.size(); i++){

            if (curr[0].back() - 10 == deck[i]){
                done = 1;
                curr[0].push_back(deck[i]);

                deck.erase(deck.begin()+i);
                break;
            }

            if (curr[1].back() - 10 == deck[i]){
                done = 1;
                curr[1].push_back(deck[i]);

                deck.erase(deck.begin()+i);
                break;
            }

            if (curr[2].back() + 10 == deck[i]){
                done = 1;
                curr[2].push_back(deck[i]);

                deck.erase(deck.begin()+i);
                break;
            }

            if (curr[3].back() + 10 == deck[i]){
                done = 1;
                curr[3].push_back(deck[i]);

                deck.erase(deck.begin()+i);
                break;
            }
        }

        if(!done){

            vector<pair<int, pair<int, int>>> res;
            // minimum, idx, row
            for(int i = 0; i < deck.size(); i++){
                if (curr[0].back() < deck[i]) res.push_back(mp(deck[i] - curr[0].back(), mp(i, 0)));
                if (curr[1].back() < deck[i]) res.push_back(mp(deck[i] - curr[1].back(), mp(i, 1)));
                if (curr[2].back() > deck[i]) res.push_back(mp(curr[2].back() - deck[i], mp(i, 2)));
                if (curr[3].back() > deck[i]) res.push_back(mp(curr[3].back() - deck[i], mp(i, 3)));
            }

            sort(res.begin(), res.end());

            if (res.empty()) break;

            int a, b, c;
            a = res[0].first;
            tie(b, c) = res[0].second;

            curr[c].push_back(deck[b]);
            deck.erase(deck.begin()+b);
        }

        if (deck.size() == 6){
            while(deck.size() < 8 && !q.empty()){
                deck.push_back(q.front());
                q.pop();
            }
        }
    }

    for(auto i : curr[0])cout <<i << ' ';
    cout <<'\n';
    for(auto i : curr[1])cout <<i << ' ';
    cout <<'\n';
    for(auto i : curr[2])cout <<i << ' ';
    cout <<'\n';
    for(auto i : curr[3])cout <<i << ' ';
    cout <<'\n';

    for(auto f :deck)cout << f<< ' ';
    cout << '\n';

    while(!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

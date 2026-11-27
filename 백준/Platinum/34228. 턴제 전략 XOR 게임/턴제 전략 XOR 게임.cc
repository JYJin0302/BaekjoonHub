#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using uint = unsigned int;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int tmp[33];

struct Node{

	Node* ch[2];
	Node(){
		ch[0] = nullptr;
		ch[1] = nullptr;
	}

};

void insert(Node* cur, int idx){
	if (idx == 30) return;
	int v = tmp[idx];

	if (!cur->ch[v]){
		Node* tmp = new Node();
		cur->ch[v] = tmp;
	}
	insert(cur->ch[v], idx+1);
}

int ans = 0;
int tval = 0;
void goSearch(Node* cur, int idx){
	if (idx == 30) return;
	int v = tmp[idx];

	if (cur->ch[v]){
		goSearch(cur->ch[v], idx+1);
	}
	else{
		tval += 1 << (29 - idx);
		goSearch(cur->ch[1-v], idx+1);
	} 
}

void solve(){

	int n;
	cin >> n;
	vector<int> A(n), B(n);
	for(auto& i : A) cin >> i;
	for(auto& i : B) cin >> i;

	int res = 0;
	for(auto f :A) res ^= f;
	for(auto f: B) res ^= f;

	Node* root = new Node();

	for(int i =0 ;i < n;i++){
		int val = B[i] ^ res;
		for(int j = 0 ;j < 30 ;j++){
			if(val & 1) tmp[29 - j] = 1;
			else tmp[29 - j] = 0;
			val >>= 1;
		}

		// cout << "SEt B: " << '\n';
		// for(int j = 0 ;j < 30 ;j++) cout << tmp[j];
		// cout << '\n';

		insert(root, 0);
	}

	for(int i =0 ; i < n;i++){
		int val = A[i];
		for(int j = 0 ;j < 30 ;j++){
			if(val & 1) tmp[29 - j] = 1;
			else tmp[29 - j] = 0;
			val >>= 1;
		}
		
		// cout << "Set A: " << A[i] << '\n';
		// for(int j = 0 ;j < 30 ;j++) cout << tmp[j];
		// cout << '\n';

		tval = 0;
		goSearch(root, 0);
		ans = max(ans, tval);

	}
	cout << ans << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
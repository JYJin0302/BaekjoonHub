#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

struct Node{
	int val, idx;
	Node(int _v = 0, int _i = 0) : val(_v), idx(_i) {}

	Node operator+(const Node& o) const{
		if (val < o.val) return Node(val, idx);
		return Node(o.val, o.idx);
	}
} seg[606060];

vector<int> A;
void init(int l, int r, int n){
	if (l == r){
		seg[n] = Node(A[l], l);
		return;
	}

	int md = (l+r)>>1;
	init(l, md, n*2);
	init(md+1, r, n*2+1);
	seg[n] = seg[n*2] + seg[n*2+1];
}

Node getMin(int l, int r, int n, int sl, int sr){
	if (l >=sl && r <=sr ) return seg[n];
	if (l > sr || r < sl) return Node(1e9+10, -1);

	int md = (l+r)>>1;
	return getMin(l, md, n*2, sl, sr) + getMin(md+1, r, n*2+1, sl, sr);
}

void solve() {
	
	int n, k;
	cin >> n >> k;
	
	A = vector<int> (n);
	for(auto& i : A) cin >> i;

	int minV = A[0], idx = 0;
	for(int i = 1; i < n;i ++){
		if (A[i] < minV){
			minV = A[i], idx = i;
		}
	}

	vector<int> tmp;
	for(int i = 0;i < n;i++) tmp.push_back(A[(idx + i) % n]);
	A = tmp;
	A.push_back(A[0]);

	init(0, n-1, 1);

	set<tuple<int, int, int, int>> st;
	Node cur = getMin(0, n-1, 1, 1, n-1);
	st.insert(make_tuple(A[0] + cur.val, cur.idx, 1, n-1));

	int ans = A[0] * 2;
	k--;
	while(k--){

		auto [a, b, c, d] = *st.begin(); st.erase(st.begin());
		ans = a;

		// c ~ b-1
		if (c <= b -1){
			Node t1 = getMin(0, n-1, 1, c, b-1);
			int val = max(A[c-1], A[b]) + t1.val;
			st.insert(make_tuple(val, t1.idx, c, b-1));
		}
		// b+1 ~ d

		if (b+1 <= d){
			Node t1 = getMin(0, n-1, 1, b+1, d);
			int val = max(A[d+1], A[b]) + t1.val;
			st.insert(make_tuple(val, t1.idx, b+1, d));
		}

	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
 	//cin >> t;
	while (t--) { solve(); }
}
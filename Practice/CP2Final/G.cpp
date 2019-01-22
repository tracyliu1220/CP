#include <bits/stdc++.h>
using namespace std;
#define MAX 300005

const int INF = 1000000000;
int N, Q;
int sum[MAX] = {0};

struct node {
	int l, r, m, value, tag;
} tree[MAX * 4];
int L(int idx) { return 2 * idx; }
int R(int idx) { return 2 * idx + 1; }

void pull(int idx) {
	tree[idx].value = min(tree[L(idx)].value, tree[R(idx)].value);
}
void push(int idx) {
	if (tree[idx].tag) {
		tree[L(idx)].value += tree[idx].tag;
		tree[R(idx)].value += tree[idx].tag;
		tree[L(idx)].tag += tree[idx].tag;
		tree[R(idx)].tag += tree[idx].tag;
		tree[idx].tag = 0;
	}
}
void build(int idx, int l, int r) {
	tree[idx].l = l;
	tree[idx].r = r;
	tree[idx].m = (l + r) / 2;
	tree[idx].tag = 0;
	if (l == r) {
		tree[idx].value = sum[l];
		return;
	}
	build(L(idx), l, tree[idx].m);
	build(R(idx), tree[idx].m + 1, r);
	pull(idx);
}
void update(int idx, int l, int r, int _value) {
	if (l <= tree[idx].l && tree[idx].r <= r) {
		tree[idx].value += _value;
		tree[idx].tag += _value;
		return;
	}
	push(idx);
	if (l <= tree[idx].m) update(L(idx), l, r, _value);
	if (r > tree[idx].m) update(R(idx), l, r, _value);
	pull(idx);
}
int find(int idx, int x) {
	if (tree[idx].l == tree[idx].r) {
		// important
		if (tree[idx].value >= 2) return tree[idx].l;
		else return INF;
	}
	push(idx);
	if (x <= tree[idx].m && x >= tree[idx].l) return find(L(idx), x);
	int t;
	if (tree[R(idx)].value >= 2) t = tree[idx].m + 1;
	else t = find(R(idx), x);
	if (t == tree[idx].m + 1) {
		if (tree[L(idx)].value >= 2) return tree[idx].l;
		t = min(t, find(L(idx), x));
	} else return t;
}

set<int> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> Q;
	string str; cin >> str;
	str = " " + str;

	for (int i = 1; i <= N; i ++) {
		if (str[i] == ')') {
			st.insert(i);
			sum[i] = sum[i - 1] - 1;
		} else {
			sum[i] = sum[i - 1] + 1;
		}
	}
	
	build(1, 1, N);
	int q;
	while (Q --) {
		cin >> q;
		if (str[q] == '(') {
			// cout << "---\n";
			// cout << q << '\n';
			str[q] = ')';
			// cout << str << '\n';
			update(1, q, N, -2);
			st.insert(q);
			int t = *(st.begin());
			cout << t << '\n';
			st.erase(st.find(t));
			update(1, t, N, 2);
			str[t] = '(';
		} else {
			// cout << "---\n";
			// cout << q << '\n';
			str[q] = '(';
			// cout << str << '\n';
			st.erase(st.find(q));
			update(1, q, N, 2);
			int t = find(1, q);
			update(1, t, N, -2);
			str[t] = ')';
			st.insert(t);
			cout << t << '\n';
		}
		// cout << str << '\n';
	}
}

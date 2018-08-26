#include <bits/stdc++.h>
using namespace std;

int tree[500000];
int input[100005];
int n, q, N;
int sum[100005];

int buildST(int index, int l, int r) {
	if (l == r) return tree[index] = input[l];

	int mid = (l + r) / 2;
	int L = buildST(index * 2, l, mid);
	int R = buildST(index * 2 + 1, mid + 1, r);

	return tree[index] = max(L, R);
}

int queryST(int index, int l, int r, int a, int b) {
	if (r < a || l > b) return 0;
	if (a <= l && r <= b) return tree[index];

	int mid = (l + r) / 2;
	int L = queryST(index * 2, l, mid, a, b);
	int R = queryST(index * 2 + 1, mid + 1, r, a, b);

	return max(L, R);
}

int BS(int n, int x) {
	int L = 0, R = n + 1, M;
	while (R - L > 1) {
		M = (L + R) / 2;
		if (sum[M] >= x) R = M;
		else L = M;
	}
	return L + 1;
}

int main() {

	int cur, pre;
	while (cin >> N && N) {

		cin >> q;
	
		int s = 1;
		n = 1;
		sum[0] = 0;

		cin >> cur;
		pre = cur;

		for (int i = 1; i < N; i ++) {
			cin >> cur;
			if (pre != cur) {
				input[n] = s;
			sum[n] = sum[n - 1] + input[n];
				s = 1;
				n ++;
			} else s ++;
			pre = cur;
		}
		
		input[n] = s;
		sum[n] = sum[n - 1] + input[n];

		buildST(1, 1, n);
		
		int a, b;
		int start, end;

		//while (cin >> a) {
		//	cout << BS(n, a) << endl;
		//}

		while (q --) {
			cin >> a >> b;
			int start = BS(n, a);
			int end = BS(n, b);

			//cout << "start = " << a << " " << b << endl;

			if (start == end) {
				cout << b - a + 1 << endl;
				continue;
			}

			int result = 0;
			if (end - start == 2) result = input[start + 1];
			if (end - start > 2) {
				//cout << "r" << endl;
				result = queryST(1, 1, n, start + 1, end - 1);
			}
			//cout << "idx: " << start << " " << end << endl;
			//cout << "s: " << sum[start] << " " << sum[end] << endl;
			//cout << "result: " << sum[start] - a + 1 << " " << result << " " << b - sum[end - 1] << endl;
			result = max(sum[start] - a + 1, result);
			result = max(b - sum[end - 1], result);

			cout << result << endl;

		}
						
	}

}

#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x) & (-x)
#define MAX 1e6+5
typedef long long LL;

LL *bit;
int n;

LL query (int x) {
	LL sum = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		sum += bit[i];
	return sum;
}

void update (int x, int val) {
	for (int i = x; i <= n; i += lowbit(i))
		bit[i] += val;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, m;
	cin >> T;

	while (T --) {
		cin >> n >> m;
		int move;

		bit = new LL[n + 5]{0};

		while (m --) {
		
			cin >> move;

			if (move == 1) {

				int l, r, x;
				cin >> l >> r >> x;
				update(l, x);
				update(r + 1, -x);

			} else if (move == 2) {

				int x;
				cin >> x;
				cout << query(x) << endl;;

			}


		}
		
		delete [] bit;	
	}


}

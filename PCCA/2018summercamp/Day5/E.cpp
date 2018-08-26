#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x)&(-x)

int arr[200005];
int local[1000];
int n, m;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (cin >> n >> m) {
		for (int i = 0; i < n; i ++)
			cin >> arr[i];

		int l = (int)sqrt(n) + 1;
		int nn = (n + l - 1) / l;

		// cout << "l  = " << l << endl;
		// cout << "nn = " << nn << endl;

		memset(local, 0, sizeof(local));

		for (int i = 0; i < l; i ++) {
			int current;
			for (int j = i * nn; j < (i + 1) * nn && j < n; j ++)
				local[i] = max(local[i], arr[j]), current = j;
			// cout << i * nn << " " << current << " " << local[i] << endl;
		}


		char c;
		int a, b;
		while (m --) {
			cin >> c >> a >> b;
			a --;

			if (c == 'Q') {
				int ans = 0;
				b --;

				if (b <= (a / nn + 1) * nn) {
					for (int i = a; i <= b; i ++)
						ans = max(ans, arr[i]);
					cout << ans << endl;
					continue;
				}

				for (int i = a; i < ((a / nn) + 1) * nn; i ++)
					ans = max(ans, arr[i]);

				for (int i = (b / nn) * nn; i <= b; i ++)
					ans = max(ans, arr[i]);

				for (int i = a / nn + 1; i < b / nn; i ++)
					ans = max(ans, local[i]);

				cout << ans << endl;
			} else {

				arr[a] = b;
				local[a / nn] = max(local[a / nn], b);
			}


		}
	}

}

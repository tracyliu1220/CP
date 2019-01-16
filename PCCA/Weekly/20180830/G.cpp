//read:		17:20
//start:	17:23
//submit:	17:43
#include <bits/stdc++.h>
using namespace std;

int lead[500005];
int n, m;

int main() {

	int cases = 1;

	while (cin >> n >> m && n && m) {
		
		for (int i = 1; i <= n; i ++)
			lead[i] = i;

		int a, b;
		for (int i = 0; i < m; i ++) {
			cin >> a >> b;
			while (lead[a] != a) a = lead[a];
			while (lead[b] != b) b = lead[b];
			lead[b] = lead[a];
		}

		int cnt = 0;
		for (int i = 1; i <= n; i ++)
			if (lead[i] == i) cnt ++;

		cout << "Case " << cases << ": " << cnt << endl;

		cases ++;
	}

}


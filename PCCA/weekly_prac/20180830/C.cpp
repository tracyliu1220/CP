//read:		15:15
//start:	15:18
//submit:	15:30	
#include <bits/stdc++.h>
using namespace std;

int n;
int m[105][105];
int c[105], r[105];

int main() {
	
	while (cin >> n && n) {

		memset(c, 0, sizeof(c));
		memset(r, 0, sizeof(r));
		
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < n; j ++) {
				cin >> m[i][j];
				c[j] ^= m[i][j];
				r[i] ^= m[i][j];
			}

		int flag = 1;
		int ans_x, ans_y;
		int founded = 0;

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				if (r[i] && c[j]) {
					r[i] = c[j] = 0;
					ans_x = i; ans_y = j;
					founded = 1;
					break;
				}
			}
			if (founded) break;
		}
		
		for (int i = 0; i < n; i ++)
			if (r[i] || c[i]) flag = 0;

		if (flag) {
			if (founded)
				cout << "Change bit (" << ans_x + 1 << "," << ans_y + 1 << ")" << endl;
			else cout << "OK" << endl;
		} else cout << "Corrupt" << endl;

	}
}

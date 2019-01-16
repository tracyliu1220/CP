//23:00
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	while (cin >> n && n) {
		n --;		
		int ans = 0;
		for (int i = 1; i <= n; i ++) {

			int cur = 12;
			for (int j = n; j >= 1; j --) {
				if (j == 1) {
					ans = i; 
					break;
				}
				int t = i % j; if (!t) t = i;
				if (cur > t) cur -= t;
				else if (cur < t) cur = j + cur - t;
				else break;
				//cout << cur << " ";
			}
			//cout << endl;
			
			if (ans) break;
		}

		cout << ans << endl;

	}

}

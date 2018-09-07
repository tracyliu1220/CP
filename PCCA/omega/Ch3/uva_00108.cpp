//UVa108
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	int graph[200][200] = {0};
	int c_sum[200][200] = {0};

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			cin >> graph[i][j];
			c_sum[i][j] = c_sum[i - 1][j] + graph[i][j];
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i ++) {
		for (int k = 0; k < i; k ++) {
			int sum = 0;
			for (int j = 1; j <= n; j ++) {
				if (sum < 0) sum = c_sum[i][j] - c_sum[k][j];
				else sum += c_sum[i][j] - c_sum[k][j];
				ans = max(ans, sum);
			}
		}
	}

	cout << ans << endl;


}

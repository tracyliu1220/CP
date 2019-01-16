//UVa10827
#include <bits/stdc++.h>
using namespace std;

int n, N;
int graph[200][200] = {0};
int c_sum[200][200] = {0};

int main() {

	cin >> N;
	while (N --) {

		memset(graph, 0, sizeof(graph));
		memset(c_sum, 0, sizeof(c_sum));

		cin >> n;
	
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				cin >> graph[i][j];
				graph[i + n][j] = graph[i][j + n] = graph[i + n][j + n] = graph[i][j];
			}
		}

		for (int i = 1; i <= 2 * n; i ++)
			for (int j = 1; j <= 2 * n; j ++)
				c_sum[i][j] = c_sum[i - 1][j] + graph[i][j];
	
		int ans = 0;
		queue<int> q;

		for (int i = 1; i <= 2 * n; i ++) {
			for (int k = i - n; k < i; k ++) {
				int sum = 0;
				int cur_n = 0;
				q.clear();
				for (int j = 1; j <= 2 * n; j ++) {
					if (sum < 0 || cur_n >= n) {
						sum = c_sum[i][j] - c_sum[k][j];
						cur_n = 1;
					} else {
						sum += c_sum[i][j] - c_sum[k][j];
						cur_n ++;
					}
					if (i == 4 && k == 1) cout << "*" << sum << endl;
					ans = max(ans, sum);
				}
			}
		}
	
		cout << ans << endl;

	}


}

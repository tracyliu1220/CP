#include <bits/stdc++.h>
using namespace std;

int N, Q;
int D, M; //D<=20, M<=10
int total, temp;
int num[205];
int dp[15][30];

int main() {

	int s = 1;

	while (cin >> N >> Q && N && Q) {
		total = 0;
		for (int i = 0; i < N; i ++)
			cin >> num[i];
		
		cout << "SET " << s++ << ":\n";

		for (int q = 1; q <= Q; q ++) {
			cin >> D >> M;
			memset(dp, 0, sizeof(dp));
			dp[0][0] = 1;

			for (int i = 0; i < N; i ++) 
				for (int r = M; r >= 1; r --) 
					for (int j = D - 1; j >= 0; j --) 
						dp[r][j] += dp[r - 1][(j + D - num[i] % D) % D];
			
			cout << "QUERY " << q << ": " << dp[M][0] << '\n';
		}
	}
}

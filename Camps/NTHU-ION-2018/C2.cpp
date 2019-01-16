#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){

	int T;
	cin >> T;

	while (T --) {
		int N, M, sum = 0;
		int current_len = 0;
		cin >> N >> M;

		int move;
		queue<pair<int, int>> q;	//length, cost

		while (N--) {
			cin >> move;

			if (move == 1) {
				
				int len;
			    int	cost;
				cin >> cost >> len;

				current_len += len;
				q.push(make_pair(len, cost));

				while (current_len > M) {
					current_len -= q.front().first;
					q.pop();
				}

			} else if (move == 2) {
				if (!q.empty()) {
					sum += q.front().second;
					current_len -= q.front().first;
					q.pop();
				}
			}

		}

		while (!q.empty()) {
			sum += q.front().second;
			q.pop();
		}

		cout << sum << endl;
	}
}

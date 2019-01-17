#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T; cin >> T; while (T --) {
		int n; cin >> n;
		deque<int> deq;
		for (int i = 0; i < n; i ++)
			deq.push_back(i);

		vector<int> ans;
		for (int i = 1; i < n; i ++) {
			for (int j = 0; j < i; j ++) {
				deq.push_back(deq.front());
				deq.pop_front();
			}
			ans.push_back(deq.front());
			deq.pop_front();
		}

		while (deq.size()) {
			ans.push_back(deq.front());
			deq.pop_front();
		}

		vector<int> output(n);
		for (int i = 0; i < n; i ++) 
			output[ans[i]] = i;

		for (int i = 0; i < n; i ++)
			cout << output[i] + 1 << " \n"[(i == n - 1)];
	}
	
}

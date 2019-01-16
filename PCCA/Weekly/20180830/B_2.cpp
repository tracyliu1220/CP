#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	while (cin >> n && n) {
		
		int m = 1;
	
		while (1) {
			queue<int> q;
			
			for (int i = 2; i <= n; i ++)
				q.push(i);
		
			while (q.size() > 1) {
				for (int i = 0; i < m - 1; i ++) {
					q.push(q.front());
					//cout << q.front() << " ";
					q.pop();
					//cout << q.front() << endl;
				}
				q.pop();
			}
			if (q.front() == 13) break;
			m ++;
		}

		cout << m << endl;

	}

}

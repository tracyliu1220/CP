#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005

int day[MAX] = {false};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n1, n2, idx;

	cin >> n1;
	for (int i = 0; i < n1; i ++) {
		cin >> idx;
		day[idx] = 1;
	}

	cin >> n2;
	for (int i = 0; i < n2; i ++) {
		cin >> idx;
		if (day[idx]) day[idx] = 3;
		else day[idx] = 2;
	}

	int pre = 3, cnt = 0;
	for (int i = 0; i < MAX; i ++) {
		if (!day[i]) continue;
		if (pre == 1) {
			if (day[i] == 1) continue;
			cnt ++;
			pre = day[i];
		} else if (pre == 2) {
			if (day[i] == 2) continue;
			cnt ++;
			pre = day[i];
		} else if (pre == 3) {
			cnt ++;
			pre = day[i];
		}
	}
	cout << cnt << '\n';
}

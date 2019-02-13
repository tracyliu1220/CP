#include <bits/stdc++.h>
using namespace std;

int state[105][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 105; i ++) {
		state[i][0] = state[i][1] = 0;
	}

	int s, n; cin >> s >> n;
	int time = 2 * n;
	int cnt = s, ptr = 0;

	while (time > 1) {
		for (int hand = 0; hand < 2; hand ++) {
			if (state[ptr][hand] == 0) {
				// cout << '*' << ptr << ' ' << cnt << '\n';
				cnt -= 1;
				if (cnt == 0) {
					// cout << ptr << ' ' << hand << '\n';
					state[ptr][0] = state[ptr][1] = 1;
					cnt = s;
					/*
					for (int i = 0; i < n; i ++)
						cout << state[i][0] << ' ';
					cout << '\n';
					for (int i = 0; i < n; i ++)
						cout << state[i][1] << ' ';
					cout << '\n';
					*/
					ptr --;
				}
				break;
			} else if (state[ptr][hand] == 1 || state[ptr][hand] == 2) {
				cnt -= 1;
			} else continue;

			if (cnt == 0) {
				// cout << ptr << ' ' << hand << '\n';
				state[ptr][hand] ++;
				cnt = s;
				if (state[ptr][hand] == 3)
					time --;
				if (time == 1) break;
				/*
				for (int i = 0; i < n; i ++)
					cout << state[i][0] << ' ';
				cout << '\n';
				for (int i = 0; i < n; i ++)
					cout << state[i][1] << ' ';
				cout << '\n';
				*/
			}
		}
		ptr += 1;
		ptr %= n;
	}

	for (int i = 0; i < n; i ++) {
		if (state[i][0] != 3 || state[i][1] != 3) {
			cout << i + 1 << '\n';
			break;
		}
	}
}

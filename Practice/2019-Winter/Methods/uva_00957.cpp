#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005

int a[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int Y, P, L;

	while (cin >> Y) {
		cin >> P;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < P; i ++) {
			cin >> a[i];
		}

		int cnt = 0, Max = -1;
		int s, t, cur = 0;
		int ms, mt;
		for (int i = 0; i < P; i ++) {
			s = a[i];
			t = a[i] + Y;
			while (cur < P && a[cur ++] < t) {
				cnt ++;
			}
			cur --;
			if (Max < cnt) {
				Max = cnt;
				ms = s;
				mt = a[cur - 1];
			}
			while (a[i] == a[i + 1]) {
				i ++;
				cnt --;
			}
			cnt --;
			if (cur >= P) break;
		}
		cout << Max << ' ' << ms << ' ' << mt << '\n';
	}
}

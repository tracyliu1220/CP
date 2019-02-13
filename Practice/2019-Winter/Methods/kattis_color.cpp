#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int S, C, K;
	cin >> S >> C >> K;

	int sock[500005];

	for (int i = 0; i < S; i ++)
		cin >> sock[i];

	sort(sock, sock + S);

	int cnt = 0;
	for (int i = 0; i < S; i ++) {
		int s = sock[i];
		int c = 0;
		cnt ++;
		while (sock[i] - s <= K && i < S && c < C) {
			i ++;
		    c ++;
		}	
		i --;
	}
	cout << cnt << '\n';
}

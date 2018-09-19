//read:		16:48
//start:	16:48
//submit:	17:05
#include <bits/stdc++.h>
using namespace std;

char m[100][100];
int dir[2][8] = { {1, 1, 1, 0, 0, -1, -1, -1},
				  {1, 0, -1, 1, -1, 1, 0 ,-1} };	

void trace(int x, int y, int b, int w) {

	if (x < 0 || x >= b || y < 0 || y >= w || m[x][y] == '*') return;

	if (m[x][y] == '@') {
		m[x][y] = '*';
		for (int i = 0; i < 8; i ++)
			trace(x + dir[0][i], y + dir[1][i], b, w);
	}
}

int main() {

	int B, W;

	while (cin >> B >> W && B && W) {
		
		for (int i = 0; i < B; i ++)
			cin >> m[i];

		int cnt = 0;
		for (int i = 0; i < B; i ++) {
			for (int j = 0; j < W; j ++) {
				if (m[i][j] == '@') {
					trace(i, j, B, W);
					cnt ++;
				}

			}
		}

		cout << cnt << endl;

	}


}

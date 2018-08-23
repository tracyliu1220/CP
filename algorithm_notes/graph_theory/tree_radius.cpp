#include <bits/stdc++.h>
using namespace std;

bool adj[9][9];
int p[9];			//DFS Tree
int h1[9], h2[9];	//最高與次高的高度
int c1[9], c2[9];	//最高與次高的來源

void record(int x, int height, int child) {
	if (height > h1[x]) {
		h2[x] = h1[x]; c2[x] = c1[x];
		h1[x] = height; c1[x] = child;
	} else if (height > h2[x]) {
		h2[x] = height; c2[x] = child;
	}
}

void DFS1(int x) {
	h1[x] = h2[x] = 0;
	for (int y = 0; y < 9; y ++)
		if (adj[x][y])
			if (y != p[x]) {
				p[y] = x;
				DFS1(y);
				record(x, h1[y] + 1, y);
			}else;
}

int main() {

}

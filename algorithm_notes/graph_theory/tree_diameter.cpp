#include <bits/stdc++.h>
using namespace std;

bool adj[9][9];
int diameter = 0;

int DFS(int x, int px) {
	int h1 = 0, h2 = 0;

	for (int y = 0; y < 9; ++ y)
		if (adj[x][y] && != px) {
			int h = DFS(y, x) + 1;
			if (h > h1) h2 = h1, h1 = h;
			else if (h > h2) h2 = h;
		}
	diameter = max(diameter, h1 + h2);
	return h1;
}

void tree_diameter() {
	diameter = 0;

	int root = 0; //pick a root randomly
	DFS(root, root);
	cout << diameter << endl;
}

int main() {
	
}

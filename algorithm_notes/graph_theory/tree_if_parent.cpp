#include <bits/stdc++.h>
using namespace std;

bool adj[9][9];
int p[9];

void DFS(int x) {
	for (int y = 0; y < 9; y++) {
		if (adj[x][y] && y != p[x]) {
			p[y] = x;
			DFS(y);
		}
	}
}

bool x_is_parent_of_y(int x, int y) {
	return x == p[y];
}

void parent_child(int root) {
	p[root] = -1;
	DFS(root);

	int x, y;
	while (cin >> x >> y)
		if (x_is_parent_of_y(x, y)) cout << "x is y's parent" << endl;
		else if (x_is_parent_of_y(y, x) cout << "y is x's parent" << endl;
		else cout << "no" << endl;
}

int main() {

}

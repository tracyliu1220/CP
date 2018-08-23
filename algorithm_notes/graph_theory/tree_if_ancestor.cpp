#include <bits/stdc++.h>
using namespace std;

bool adj[9][9];
int tin[9], tout[9]; // DFS進入及離開各點的時刻
int t = 0; //現在時刻

void DFS(int x, int px) { //px是x的父親
	tin[x] = t ++;
	
	for (int y = 0; y < 9; ++ y)
		if (adj[x][y] && y != px) DFS(y, x);

	tout[x] = t ++;
}

bool x_is_ancestor_of_y(int x, int y) {
	return tin[x] < tin[y] && tout[x] > tout[y];
}

void ancestor_descendant(int root) {
	t = 0;
	for (int i = 0; i < 9; i ++) tin[i] = 0;
	DFS(root, root);

	int x, y;
	while (cin >> x >> y) {
		if (x_is_ancestor_of_y(x, y)) cout << "yes" << endl;
		else cout << "no" << endl;
	}
}

int main() {

}

#include <bits/stdc++.h>
using namespace std;

int adj[9][9], size[9];
int ref[9];

void topological_ordering() {
	for (int i = 0; i < 9; i ++) ref[i] = 0;

	for (int i = 0; i < 9; i ++)
		for (int j = 0; j < size[i]; j ++)
			ref[adj[i][j]] ++;

	queue<int> Q;
	for (int i = 0; i < 9; i ++)
		if (ref[i] == 0) Q.push(i);

	for (int i = 0; i < 9; i ++) {
		if (Q.empty()) break;

		int s = Q.front(); Q.pop();
		ref[s] = -1;

		cout << s;

		for (int j = 0; j < size[s]; j ++) {
			int t = adj[s][j];
			ref[t] --;
			if (!ref[t]) Q.push(t);
		}
	}
}

int main() {
	
}

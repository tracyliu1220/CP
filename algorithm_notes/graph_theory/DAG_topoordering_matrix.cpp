#include <bits/stdc++.h>
using namespace std;

bool adj[9][9];
int ref[9]; //紀錄每個點被多少條邊連到

void topological_ordering(){
	for (int i = 0; i < 9; i ++) ref[i] = 0;

	for (int i = 0; i < 9; ++i)
		for (int j = 0; j < 9; j ++)
			if (adj[i][j]) ref[j] ++;

	for (int i = 0; i < 9; i ++) {
		int s = 0;
		while (s < 9 && ref[s] != 0) s ++;

		if (s == 9) break;

		ref[s] = -1; //founded

		cout << s;

		for (int t = 0; t < 9; ++ t)
			if (adj[s][t]) ref[t] --;
	}
}

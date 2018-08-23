#include <bits/stdc++.h>
using namespace std;
#define MAX 1e9

int C[40][40], F[40][40], R[40][40];
int vis[40];
int pre[40];
const int n = 38;
int sum = 0;

bool BFS(int s, int t) {
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(s);
	pre[s] = s;
	vis[s] = 1;

	int cur;
	while (!q.empty()) {
		cur = q.front(); q.pop();
		for (int i = 0; i < n; i ++) {
			if (!vis[i] && R[cur][i] > 0) {
				vis[i] = 1;
				pre[i] = cur;
				if (i == t) {
					// ans[cur] = pre[cur];
					while (!q.empty()) q.pop();
					return true;
				}
				q.push(i);
			}
		}
	}
	return false;
}

int EK(int s, int t) {
	memcpy(R, C, sizeof(C));
	memset(F, 0, sizeof(F));

	int cnt = 0;

	while (BFS(s, t)) {
		int d = 1e9;
		for (int i = t; i != s; i = pre[i])
			d = min(d, R[pre[i]][i]);
		for (int i = t; i != s; i = pre[i]) {
			F[pre[i]][i] += d;
			F[i][pre[i]] = -F[pre[i]][i];
			R[pre[i]][i] = C[pre[i]][i] - F[pre[i]][i];
			R[i][pre[i]] = C[i][pre[i]] - F[i][pre[i]];
		}
		cnt += d;
	}

	return cnt;
}

void print() {
	int maxflow = EK(0, 37);
	if (maxflow == sum) {
		for (int i = 27; i <= 36; i ++) { 
			int tar = 1;
			while (!F[tar][i] && tar < 30) tar ++;
				if (tar > 26) cout << '_';
				else cout << (char)(tar + 'A' - 1);
		}
		cout << endl;
			//	cout << "end" << endl;			
	} else cout << '!' << endl;
	sum = 0;
	memset(C, 0, sizeof(C));
}

int main() {
	string s, s1, s2;
	
	while (1) {

		if(!getline(cin, s, '\n')) {
			print();   
			break;	
		}	
		
		if(s == "") {
			print();
			continue;
		}

		stringstream ss;
		ss << s;
		ss >> s1 >> s2;
		
		int letter = (int)(s1[0] - 'A' + 1);
		C[0][letter] = (int)(s1[1] - '0');
		sum += C[0][letter];

		for (int i = 0; i < s2.size() - 1; i ++) {
			int num = (int)(s2[i] - '0') + 27;
			C[letter][num] = 1;
			C[num][37] = 1;
		}

	}

}

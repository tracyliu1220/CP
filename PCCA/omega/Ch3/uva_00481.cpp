/*
 * https://blog.csdn.net/mobius_strip/article/details/8230052
 */
#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

int data[MAX];
int len[MAX];
int front[MAX];
int Q[MAX];

void output(int v) {
	if (front[v]) output(front[v]);
	cout << data[v] << '\n';
}

int bs(int r, int v) {
	int L = 1;
	while (L < R) {
		int M = (L + R) >> 1;
		if (data[Q[M]] < v) L = M + 1;
		else R = M;
	}
	return R;
}

int main() {
	int cnt = 1;
	while (cin >> data[cnt]) cnt ++;

	int tail = 0;
	Q[++tail] = 1;
	for (int i = 2; i < cnt; i ++) {
		if (data[Q[tail]] < data[i]) {
			Q[++tail] = i;
			front[i] = Q[tail-1];
		}else {
			int idx = bs(tail, data[i]);
			Q[id] = i;
			front[i] = Q[id-1];
		}
	}

	cout << tail << endl;
	output(Q[tail]);
}


/*
#include <bits/stdc++.h>
using namespace std;
#define MAX 100005

const int INF = 2147483645;

vector<int> ans(MAX, INF);
vector<int> num(MAX);
vector<int> dp(MAX);
vector<int> print(MAX);
int Ans = -1;
int cur;

int main() {

	int idx = 0;

	while (cin >> num[idx]) {

		vector<int>::iterator tar = lower_bound(ans.begin(), ans.end(), num[idx]);
		*tar = num[idx];
		
		dp[idx] = (int)(tar - ans.begin());
		//cout << "*" << dp[idx] << endl;
		//cout << (int)(tar - ans.begin()) << endl;
		//for (int i = 0; i < 10; i ++)
		//	cout << ans[i] << " ";
		//cout << endl;
		
		Ans = max(Ans, (int)(tar - ans.begin()));
		idx ++;
	}

	//cout << endl;

	cout << ++Ans << "\n-";

	int a = Ans - 1;
	for (int i = idx - 1; i >= 0; i --) {
		if (a == -1) break;
		if (dp[i] == a) {
			print[a] = num[i];
			a --;
		}
	}

	for (int i = 0; i < Ans; i ++) {
		cout << '\n' << print[i];
	}


}
*/

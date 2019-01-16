#include <bits/stdc++.h>
using namespace std;

map<int, int> m;
queue<int> q;
int n, x;
int r;
int* a;
int ANS = 1e9;
int flag = 0;

void BFS(int k, int ans){
	if(ans > n) return;
	int pre = a[k];
	a[k] &= x;

	if(a[k] != pre && m.count(a[k]) && m[a[k]] == 1){
		cout << ans << endl;
		flag = 1;
		if(ans < ANS) ANS = ans;
		return;
	}

	m[a[k]] = 1;

	for(int i = 0; i < n; i ++)
		BFS(i, ++ ans);

	a[k] = pre;
	m[a[k]] = 0;

	for(int i = 0; i < n; i ++)
		BFS(i, ++ ans);

}

int main(){

	cin >> n >> x;
	r = n + 2;

	a = new int[n];
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(m.count(a[i])) flag = 1;
		m[a[i]] = 1;
	}


	if(flag){
		cout << 0 << endl;
		return 0;
	}else
		for(int i = 0; i < n; i ++)
			BFS(i, 1);

	if(flag)
		cout << ANS << endl;
	else
		cout << -1 << endl;
}

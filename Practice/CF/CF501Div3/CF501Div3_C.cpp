#include <bits/stdc++.h>
using namespace std;

int N, X;
vector<pair<int, int> > v;

int DFS(int n, int sum){
	if(n == N) return 1;
	if(sum > X) return 0;
	return DFS(n + 1, sum + v[n].first) + DFS(n + 1, sum + v[n].second);
}

int main(){

	cin >> N >> X;
	v.resize(N);
	for(int i = 0; i < N; i ++)
		cin >> v[i].first >> v[i].second;
	
	int ans = DFS(0, v[0].first) + DFS(0, v[0].second);
	if(ans) cout << ans << endl;
	else cout << -1 << endl;
}

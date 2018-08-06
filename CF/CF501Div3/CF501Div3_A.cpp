#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	vector<pair<int, int> > v(n);

	for(int i = 0; i < n; i ++)
		cin >> v[i].first >> v[i].second;

	vector<int> ans;
	for(int i = 1; i <= m; i ++){
		int flag = 0;
		for(int j = 0; j < n; j ++){
			if(v[j].first <= i && i <= v[j].second)
				flag = 1;
		}
		if(!flag) ans.push_back(i);
	}

	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i ++)
		cout << ans[i] << " ";
	cout << endl;
}

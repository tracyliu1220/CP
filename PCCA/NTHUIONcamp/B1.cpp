#include <bits/stdc++.h>
using namespace std;
#define MAX 1e9+7

int n, m;
vector<int> v;

int main(){
	
	int cases;
	cin >> cases;

	while (cases --) {
		
		cin >> n >> m;

		v.resize(n + 1); //cost, index

		v[0] = 0;
		for (int i = 1; i < n + 1; i ++)
			cin >> v[i];

		sort (v.begin(), v.end());

		int target;
		vector<int>::iterator ans;
		for(int i = 0; i < m; i ++){
			cin >> target;
			ans = lower_bound(v.begin(), v.end(), target);
			cout << *(++ans) << endl;
		}

		cout << endl;

		v.clear();
	}
}

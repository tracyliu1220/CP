#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k; //people, food

	vector<pair<int, int> > food; //people, food

	map<int, int> m;
	map<int, int>::iterator iter;
	int temp;

	for(int i = 0; i < k; i ++){
		cin >> temp;
		m[temp] ++;
	}

	for(iter = m.begin(); iter != m.end(); iter ++){
		food.push_back(make_pair(0, iter->second));
	}

	for(int i = 0; i < n; i ++){
		int Max = 0;
		for(int i = 0; i < food.size(); i ++){
			if(food[i].second / (food[i].first + 1.0) > food[Max].second / (food[Max].first + 1.0))
					Max = i;
		}
		food[Max].first ++;
	}

	double Min = 10000;
	for(int i = 0; i < food.size(); i ++){
		if(food[i].second / (double)food[i].first < Min)
			Min = food[i].second / (double)food[i].first;
	}

	int ans = Min;

	cout << ans << endl;

}

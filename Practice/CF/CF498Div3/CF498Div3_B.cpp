/*
	AC
*/
#include <bits/stdc++.h>
using namespace std;

bool compare1(pair<int, int> a, pair<int, int> b){
	if(a.first > b.first) return true;
	else return false;
}

bool compare(pair<int, int> a, pair<int, int> b){
	if(a.second < b.second) return true;
	else return false;
}

int main(){

	int n, t;
	cin >> n >> t;

	int current;
	vector<pair<int, int> > v;
	for(int i = 1; i <= n; i ++){
		cin >> current;
		v.push_back(make_pair(current, i));
	}

	sort(v.begin(), v.end(), compare1);

	sort(v.begin(), v.begin() + t, compare);

	int sum = 0;
	for(int i = 0; i < t; i ++)
		sum += v[i].first;
	cout << sum << endl;

	if(t > 1){
		cout << v[1].second - 1 << " ";
		for(int i = 2; i < t; i ++)
			cout << v[i].second  - v[i - 1].second << " ";
		cout << n - v[t - 1].second + 1 << endl;
	}else{
		cout << n << endl;
	}
}

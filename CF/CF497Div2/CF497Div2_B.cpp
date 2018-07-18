#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int flag = 1;
	vector<pair<int, int> > v;

	int w, l;
	for(int i = 0; i < n; i ++){
		cin >> w >> l;
		if(w > l)
			v.push_back(make_pair(w, l));
		else
			v.push_back(make_pair(l, w));
	}

	int current = v[0].first;

	for(int i = 1; i < n; i ++){
		if(current >= v[i].first){
			current = v[i].first;
		}else if(current >= v[i].second){
			current = v[i].second;
		}else{
			flag = 0;
			break;
		}
	}

	if(flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


}

#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int BS(int x, vector<int> & v){
	int L = 0;
	int R = v.size() - 1;
	int M;
	while(R - L > 1){
		M = (L + R) / 2;
		if(v[M] <= x)
			L = M;
		else
			R = M;
	}
	return L;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, temp;
	int target;
	
	while(cin >> n){
		int num[MAX] = {0};
		vector<int> v(n); 
		for(int i = 0; i < n; i ++){
			 cin >> v[i];
			 num[v[i]] = 1;
		}
		
		sort(v.begin(), v.end());
		
		int ans;
		cin >> target;
		
		int start = BS(target / 2, v);

		for(int i = start; i >= 0; i --){
			if(num[target - v[i]]){
				ans = i;
				break;
			}
		}
		cout << "Peter should buy books whose prices are " << v[ans] <<" and " << target - v[ans] << "." << endl;
		cout << endl;
	}
}

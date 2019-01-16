#include <bits/stdc++.h>
using namespace std;

struct condition{
	int first;
	int second;
	int seat;
};

int main(){

	int n, m;

	while(1){
		cin >> n >> m;
		if(!n && !m) break;

		int s[8] = {0, 1, 2, 3, 4, 5, 6, 7};
		condition temp;
		vector<condition> v(m);

		for(int i = 0; i < m; i ++){
			cin >> temp.first >> temp.second >> temp.seat;
			v[i] = temp;
		}

		int count = 0;

		do{
			int flag = 1;
			//test each contidion
			for(int i = 0; i < m; i ++){
				int *first_index = find(s, s + n, v[i].first);
				int *second_index = find(s, s + n, v[i].second);
				int seat = abs(first_index - second_index);

				if(v[i].seat > 0 && seat > v[i].seat) flag = 0;
				else if(v[i].seat < 0 && seat < -v[i].seat) flag = 0;
			}
			if(flag) count ++;
		}while(next_permutation(s, s + n));

		cout << count << endl;
		
	}


}

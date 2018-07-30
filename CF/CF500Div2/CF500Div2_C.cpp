#include <bits/stdc++.h>
using namespace std;
#define MAX 1e9+7

int main(){
	long long max_x = 0, min_x = MAX, max_y = 0, min_y = MAX;
	int n;

	cin >> n;

	int num[2 * n];

	for(int i = 0; i < 2 * n; i ++)
		cin >> num[i];

	sort(num, num + 2 * n);
	int current_x, current_y;

	for(int i = 0; i < n; i ++){
		current_x = num[i];

		if(current_x > max_x) max_x = current_x;
		if(current_x < min_x) min_x = current_x;
	}

	for(int i = n; i < 2 * n; i ++){
		current_y = num[i];
		if(current_y > max_y) max_y = current_y;
		if(current_y < min_y) min_y = current_y;
	}


	cout << (max_x - min_x) * (max_y - min_y) << endl;

}

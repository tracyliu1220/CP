#include <bits/stdc++.h>
using namespace std;

int n;
int *a;
long long ANS = 1e18;

void DFS(int k, long long max_x, long long min_x, long long max_y, long long min_y, int c_x, int c_y){

	
	if(k == 2 * n){
		long long ans = (max_x - min_x) * (max_y - min_y);
		if(ans < ANS) ANS = ans;
		return;
	}

	int new_max_x = max_x,
	   	new_min_x = min_x,
	   	new_max_y = max_y,
	   	new_min_y = min_y;

	if(a[k] > new_max_x) new_max_x = a[k];
	if(a[k] < new_min_x) new_min_x = a[k];
	if(a[k] > new_max_y) new_max_y = a[k];
	if(a[k] < new_min_y) new_min_y = a[k];

	if(c_x < n)
		DFS(k + 1, new_max_x, new_min_x, max_y, min_y, c_x + 1, c_y);
	if(c_y < n)
		DFS(k + 1, max_x, min_x, new_max_y, new_min_y, c_x, c_y + 1);
}

int main(){
	cin >> n;
	a = new int[2 * n];

	for(int i = 0; i < 2 * n; i ++)
		cin >> a[i];

	DFS(0, 0, 1e9, 0, 1e9, 0, 0);

	cout << ANS << endl;
}

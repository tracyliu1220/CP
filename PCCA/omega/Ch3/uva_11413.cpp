#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int items[MAX];

int container_size (int size, int value) {
	int sum = 0, count = 1;
	for (int i = 0; i < size; i ++){ 
		if (items[i] > value) return size;
		if (sum + items[i] > value) {
			sum = items[i];
			count ++;
		}else {
			sum += items[i];
		}
	}
	return count;
}

int main(){

	int n, m;
	while (cin >> n >> m) {
		int sum = 0, Max = 0;
		for (int i = 0; i < n; i ++) {
			cin >> items[i];
			sum += items[i];
			if (Max < items[i]) {
				Max = items[i];
			}
		}

		int L = Max, R = sum, M = 0;

		while (L < R) {
			M = (L + R) / 2;
			if (container_size(n, M) <= m) R = M;
			else L = M + 1;
		}

		cout << L << endl;
	}
}

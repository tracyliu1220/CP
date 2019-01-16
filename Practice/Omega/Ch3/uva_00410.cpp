#include <bits/stdc++.h>
using namespace std;

struct sets{
	int index;
	int member1;
	int member2;
};

int main(){
	int m, n;
	int cases = 1;

	while(cin >> m >> n){

		int num[20] = {0};
		int sum = 0;
		for(int i = 0; i < n; i ++){
			cin >> num[i];
			sum += num[i];
		}

		sort(num, num + 2 * m);

		double average = sum / (double)m;
		
		//output
		double imbalance = 0;
		printf("Set #%d\n", cases);
		for(int i = 0; i < m; i ++){
			printf("%2d:", i);
			if(num[i])				printf(" %d", num[i]);
			if(num[2 * m - i - 1])	printf(" %d", num[2 * m - i - 1]);
			printf("\n");
			imbalance += fabs(num[i] + num[2 * m - i - 1] - average);
		}
		printf("IMBALANCE = %.5f\n\n", imbalance);
		cases ++;
	}
}

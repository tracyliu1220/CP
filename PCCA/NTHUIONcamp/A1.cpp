#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int T;
	scanf("%d", &T);

	while(T --){
		int N;
		scanf("%d", &N);
		
		double sum = 0;
		double temp;
		while(N --){
			scanf("%lf", &temp);
			if(temp < 0){
				temp = -temp;
				int add = temp * 87 + 0.5;
				temp = add / 100.0;
				sum -= temp;
			}else{
				int add = temp * 87 + 0.5;
				temp = add / 100.0;
				sum += temp;
			}
		}
		
		if(sum > 0)
			printf("%.2f\n", sum);
		else
			printf("0.00\n");

	}
}

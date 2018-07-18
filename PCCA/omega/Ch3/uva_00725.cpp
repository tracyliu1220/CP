#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);

	while(1){
		if(!n) break;
		int print = 0;

		for(int fghij = 1234; fghij <= 98765 / n; fghij ++){
			int	abcde = fghij * n;
			int used = (fghij < 10000);
			int temp = abcde;
			while(temp){
				used |= 1 << (temp % 10);
				temp /= 10;
			}
			temp = fghij;
			while(temp){
				used |= 1 << (temp % 10);
				temp /= 10;
			}
			if(used == (1 << 10) - 1){
				printf("%0.5d / %0.5d = %d\n", abcde, fghij, n);
				print = 1;
			}
		}

		if(!print) printf("There are no solutions for %d.\n", n);

		scanf("%d", &n);
		if(n) printf("\n");
	}
}

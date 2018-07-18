#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

	int input1,input2;
	int i;
	
	scanf("%d", &input1);
	int a1[input1];
	for(i = 0; i < input1; i++)
		scanf("%d", &a1[i]);
		
	scanf("%d", &input2);
	int a2[input2];
	for(i = 0; i < input2; i++)
		scanf("%d", &a2[i]);
		
	for(i = 0; i < input2; i++){
		
		int M;
		int L1 = 0, R1 = input1 - 1;
		int L2 = 0, R2 = input1 - 1;
		
		if(a2[i] == a1[0] && a2[i] == a1[input1 - 1]){
			L1 = -1;
			R2 = -1;	
		}
		else if(a2[i] == a1[0]){
			L1 = -1;
			R2 = 0;
			while(a1[R2] == a2[i])
				R2 ++;
		}
		else if(a2[i] == a1[input1 - 1]){
			L1 = input1 - 2;
			while(a1[L1] == a2[i])
				L1 --;
			R2 = -1;
		}
		else if(a2[i] < a1[0]){
			L1 = -1;
			R2 = 0;
		}
		else if(a2[i] > a1[input1 - 1]){
			L1 = input1 - 1;
			R2 = -1;
		}
		else{
			while(a1[L1+1] < a2[i]){
				M = (L1 + R1)/2;
				if(a1[M] < a2[i])
					L1 = M;
				else
					R1 = M;
			}
			while(a1[R2-1] > a2[i]){
				M = (L2 + R2)/2;
				if(a1[M] > a2[i])
					R2 = M;
				else
					L2 = M;
			}
		}
		
		
		
		
		if(L1 == -1)
			printf("X");
		else
			printf("%d", a1[L1]);
			
		if(R2 == -1)
			printf(" X\n");
		else
			printf(" %d\n", a1[R2]);
		
	}
	

	return 0;
}

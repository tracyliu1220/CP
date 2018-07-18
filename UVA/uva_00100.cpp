#include <stdio.h>
#include <stdlib.h>

long int circle(long int n){
	if(n == 1)
		return 1;
	else if(n % 2)
		return 1 + circle(3 * n + 1);
	else
		return 1 + circle(n / 2);
}

int main(int argc, char *argv[]) {
	long int max, current, last, i, n1, n2;
	
	
	while(scanf("%ld %ld", &current, &last) == 2){
		
	if(current < last){
		n1 = current;
		n2 = last;
	}else{
		n1 = last;
		n2 = current;
	}
	
	max = circle(n1);
	
	for(i = n1; i <= n2; i++){
		if(circle(i) > max)
			max = circle(i);
	}
	
	printf("%ld %ld %ld\n", current, last, max);
	
	}

	return 0;
}


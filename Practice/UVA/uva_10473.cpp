#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	
	
	char num[33],num2[33];
	long int number;
	
	while(scanf("%s",num) != -1){
		
		if(strtol(num,NULL,10)<0)
			break;
		
		if(num[1]=='x'){
			number = strtol(num,NULL,16);
			
			printf("%d\n",number);
		}
		else{
			printf("0x%X\n",strtol(num,NULL,10));
		}
			
	}
	
	
	
}

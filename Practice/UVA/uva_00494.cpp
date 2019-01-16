#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){
	
	char word[1000];
	char w;
	int count = 0,i=0;
	
	while(gets(word)){
		count = 0;
		for(i=0;i<strlen(word);i++){
			if((word[i]>='a' && word[i]<='z' || word[i]>'A' && word[i]<='Z') && !(word[i+1]>='a' && word[i+1]<='z' || word[i+1]>='A' && word[i+1]<='Z'))
				count++;
		}
	
		printf("%d\n",count);
	}
	
	
	
}

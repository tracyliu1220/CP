#include <iostream>
#include <vector>
#include <stdio.h>
#include <list>
#include <string.h>
#include <algorithm>
using namespace std; 

vector<char> arr;

void swap(char *a, char*b){
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void printAll(){ 
    sort(arr.begin(),arr.end());
    do{
        for(int i=0;i<arr.size();++i)
            printf("%c",arr[i]);
        puts("");
    } while(next_permutation(arr.begin(),arr.end()));
}

int main(){
	
	int i,j;
	char c;
	int n;
	int count=0;
	char input[12];
	
	scanf("%d", &n);
	
	
	for(i = 0; i < n; i++){
		scanf("%s", input);
		for(j = 0; j < strlen(input); j++){
			c = input[j];
			arr.push_back(c);
			count++;
		}
		sort(arr.begin(),arr.end());
		printAll();
		count = 0;
		arr.clear();
		printf("\n");
	}
	
}

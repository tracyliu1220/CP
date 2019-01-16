#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int times;
	cin >> times;
	
	for(int i = 0; i < times; i++){
		int b1 = 0, b2 = 0;
		char num_string[10];
		cin >> num_string;
		long int num = strtol(num_string, NULL, 10);
		while(num > 0){
			if(num % 2 == 1)
				b1 ++;
			num /= 2;
		}
		cout << b1;
		num = strtol(num_string, NULL, 16);
		while(num > 0){
			if(num % 2 == 1)
				b2 ++;
			num /= 2;
		}
		cout << " " << b2 <<endl;
		
	}



	return 0;
}


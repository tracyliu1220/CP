#include <bits/stdc++.h>
using namespace std;

int main() {
	char str[1000];
	int state = 1;
	while (fgets(str, 1005, stdin) != NULL) {
		for (int i = 0; str[i]; i ++) 
			if (str[i] == '\"' && state) { 
				printf("``");
				state = 0;
			} else if (str[i] == '\"') {
				printf("\'\'");
				state = 1;
			} else printf("%c", str[i]);
	}
}

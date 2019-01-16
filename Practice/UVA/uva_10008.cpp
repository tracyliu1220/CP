#include <iostream>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <iterator>
using namespace std;

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	char c;
	map<char, int> m;
	map<char, int>::iterator iter, print_iter;
	
	while(scanf("%c", &c) != -1){
		
		if(c >= 'a' && c <= 'z'){
			c -= 32;
			if(m.find(c) == m.end()){
				m[c] = 1;
			}else{
				m[c] ++;
			}
		}else if(c >= 'A' && c <= 'Z'){
			if(m.find(c) == m.end()){
				m[c] = 1;
			}else{
				m[c] ++;
			}
		}else
			continue;
	}
	
	
	int print_key;
	int print_value = 0;
	int map_size = m.size();
	
	while(map_size > 0){
		for(iter = m.begin(); iter != m.end(); iter++){
			if(iter->second > print_value){
				print_value = iter->second;
				print_key = iter->first;
				print_iter = iter;
			}
		}
		printf("%c %d\n", print_key, print_value);
		m.erase(print_iter);
		map_size --;
		print_value = 0;
	}

	return 0;
}


#include <stdio.h>
#include <stdlib.h>

char map[100][100];

void trace(int cur_x, int cur_y, int b, int w){
	
	int i,j;
	
	if(cur_x < 0 || cur_x >= b || cur_y < 0 || cur_y >= w || map[cur_x][cur_y] == '*')
		return;
		
	
	if(map[cur_x][cur_y] == '@'){
		map[cur_x][cur_y] = '*';
		trace(cur_x+1, cur_y+1, b, w);
		trace(cur_x+1, cur_y, b, w);
		trace(cur_x+1, cur_y-1, b, w);
		trace(cur_x, cur_y+1, b, w);
		trace(cur_x, cur_y-1, b, w);
		trace(cur_x-1, cur_y+1, b, w);
		trace(cur_x-1, cur_y, b, w);
		trace(cur_x-1, cur_y-1, b, w);
		map[cur_x][cur_y] = '*';
	}
}

int main(int argc, char *argv[]) {
	
	while(1){

	int b,w;
	int i,j;
	int count = 0;
	scanf("%d %d", &b, &w);
	
	if(b == 0 || w == 0)
		break;
	
	for(i = 0; i < b; i++){
		scanf("%s", map[i]);
	}
	
	
	for(i = 0; i < b; i++){
		for(j = 0; j < w; j++){
			if(map[i][j] == '@'){
				map[i][j] == '*';
				trace(i, j, b, w);
				count++;
			}
		}
	}

	printf("%d\n", count);
	
	}

	return 0;
}

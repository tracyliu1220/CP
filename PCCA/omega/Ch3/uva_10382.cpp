/*
	WA 
*/
#include <bits/stdc++.h>
using namespace std;

int n, l, w;

bool compare(pair<double, double> a, pair<double, double> b){
	if(a.first < b.first) return true;
	else if(a.first == b.first){
		if(a.second >= b.second) return true;
		else return false;
	}else return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(cin >> n >> l >> w){
		
		vector<pair<double, double> > circles(n);	//start, end
		double x, r;
		double len;

		int index = 0;

		for(int i = 0; i < n; i ++){
			cin >> x >> r;
			if(r <= w / 2) continue;
			len = sqrt(r * r - w * w / 4.0);
			//cout << "len= " << len << endl;
			circles[index].first = x - len;
			circles[index].second = x + len;
			index ++;
		}

		sort(circles.begin(), circles.begin() + index, compare);

		//for(int i = 0; i < index; i ++)
		//	cout << circles[i].first << " " << circles[i].second << endl;

		int flag = 0;
		int cnt = 0;
		double left = 0, right = 0;

		if(circles[0].first <= 0){

			int i = 0;

			while(i < index){

				int j = i;
				while(j < index && circles[j].first <= left){
					if(circles[j].second > right)
						right = circles[j].second;
					j ++;
				}

				if(j == i) break;

				cnt ++;
				left = right;
				i = j;

				if(right >= l){
					flag = 1;
					break;
				}

			}


		}
//
//		if(circles[current_x].first >= 0) flag = 0;
//
//		while(circles[current_x].second < l && flag){
//			double current_max = 0;
//			for(int i = current_x; i < index; i ++)
//				if(circles[i].first < circles[current_x].second && circles[i].second >= circles[current_x].second){
//					if(circles[i].second >= circles[current_max].second)
//						current_max = i;
//				}
//
//			if(current_x == current_max){flag = 0; break;}
//
//			current_x = current_max;
//			//cout << "*" << circles[current_x].second << endl;
//
//			cnt ++;
//		}

		if(flag) cout << cnt << endl;
		else cout << -1 << endl;

		circles.clear();
	}
}

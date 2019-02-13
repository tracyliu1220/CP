#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long LL;

LL t[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, T; cin >> N >> T;
	int A, B, C, t0; cin >> A >> B >> C >> t0;

	t[0] = t0;
	for (int i = 1; i < N; i ++) 
		t[i] = ((A * t[i - 1] + B) % C) + 1;

	sort(t, t + N);
	
	LL sum = 0, cnt = 0;
	for (int i = 0; i < N; i ++) {
		if (i) t[i] += t[i - 1];	
		if (t[i] <= T) {
			sum += t[i];
			sum %= MOD;
			cnt ++;
		}
	}
	cout << cnt << ' ' << sum << '\n';
}

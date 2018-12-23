#include <bits/stdc++.h>
using namespace std;
#define MAX 10005

int a[MAX];

int main() {
    int i = 0;
    while (cin >> a[i]) {
        i ++;
        sort(a, a + i);
        if (i % 2) cout << a[i / 2] << '\n';
        else cout << (a[i / 2 - 1] + a[i / 2]) / 2 << '\n';
    }
}

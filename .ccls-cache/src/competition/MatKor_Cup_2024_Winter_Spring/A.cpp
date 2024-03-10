#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a;
	double N,M;

	cin >> a;
	cin >> N >> M;

	double ans = 0x3f3f3f3f;

	ans = min(ans, N/a * 2);
	ans = min(ans, M/a * 2);
	ans = min(ans, max(N/a, M));
	ans = min(ans, max(N, M/a));

	cout << fixed;
	cout.precision(7);

	cout << ans << "\n";
	
	return 0;
}

/*
06:39
240309 
*/
#define INF 0x3f3f3f3f
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x,y,w,h;
	cin >> x >> y >> w >> h;
	int ans = INF;
	ans = min(ans,abs(x-w));
	ans = min(ans,abs(y-h));
	ans = min(ans,abs(x));
	ans = min(ans,abs(y));

	cout << ans << "\n";

	return 0;
}

/*
01:58 
240528 02:22
*/
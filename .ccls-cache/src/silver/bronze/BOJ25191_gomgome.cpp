#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a,b,c;
	cin >> a >> b >> c;
	int ans=b/2+c;
	ans = min(ans,a);

	cout << ans << "\n";
	return 0;
}

/*
01:05
240529
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int L,R,A;
	cin >> L >> R >> A;

	int D = abs(L-R);
	int ans;
	if(A>=D)
		ans =(L+R+A)/2*2;
	else
		ans = (min(L,R)+A)*2;
	cout << ans << "\n";
	
	return 0;
}

/*
03:17 Problem Analysis.
04:51 
240623 05:57
*/
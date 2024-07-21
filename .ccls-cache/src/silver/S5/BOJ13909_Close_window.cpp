#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	int ans=0;
	for(int i=1;i<=sqrt(N);i++){
		ans++;
	}
	cout << ans << "\n";
	
	return 0;
}

/*
01:45 Problem Analysis.
03:29 TC passed.
240721 03:51
*/
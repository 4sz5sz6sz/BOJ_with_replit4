#define INF 0x3f3f3f3f
#define IDX_MAX 100001
#include<bits/stdc++.h>
using namespace std;

int DP[IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	DP[1] = 1;
	for(int cur=2;cur<=N;cur++){
		DP[cur] = INF;
		for(int j=1;cur-j*j >= 0;j++){
			DP[cur] = min(DP[cur-j*j]+1,DP[cur]);
		}
	}

	cout << DP[N] << "\n";
	
	return 0;
}

/*
07:03 Problem Analysis.
08:59 TC pased.
240508 08:59
*/
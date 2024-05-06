#define IDX_MAX 26
#include<bits/stdc++.h>
using namespace std;

int A[IDX_MAX];
int DP[IDX_MAX][2];
int N;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i=1;i<=N;i++){
		int a,b;
		cin >> a >> b >> A[i];
	}

	for(int i=1;i<=N;i++){
		DP[i][0] = max(DP[i-1][0], DP[i-1][1]);
		DP[i][1] = DP[i-1][0] + A[i];
	}

	cout << max(DP[N][0], DP[N][1]);
	
	return 0;
}

/*
03:19 Problem Analysis.
06:38 TC passed.
240506 06:41
*/
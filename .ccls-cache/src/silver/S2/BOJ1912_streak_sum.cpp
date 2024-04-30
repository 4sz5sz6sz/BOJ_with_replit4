#define INF 0x3f3f3f3f
#define IDX_MAX 100007
#include <bits/stdc++.h>
using namespace std;

int N;
int A[IDX_MAX];
int DP_L[IDX_MAX];
int DP_R[IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	cin >> N;

	for(int i=1;i<=N;i++){
		cin >> A[i];
	}
	
	for(int i=1;i<=N;i++){
		DP_L[i] = max(DP_L[i-1],0) + A[i];
	}

	for(int i=N;i>=1;i--){
		DP_R[i] = max(DP_R[i+1],0) + A[i];
	}

	int ans=-INF;
	for(int i=1;i<=N;i++){
		int cur = DP_L[i] + DP_R[i] - A[i];
		ans = max(ans, cur);
	}

	cout << ans << "\n";

	return 0;
}

/*
00:30 Problem Analysis.
04:27 main() Completed.
05:12 TC passed.

240430 05:18
*/
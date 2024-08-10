#define IDX_MAX 10007
#include<bits/stdc++.h>
using namespace std;

int arr[IDX_MAX];
int DP[IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	for(int i=1;i<=N;i++){
		cin >> arr[i];
	}

	DP[1] = arr[1];
	if(N>=2){
		DP[2] = arr[1] + arr[2];
	}


	
	for(int i=3;i<=N;i++){
		DP[i] = max(DP[i-2], DP[i-3] + arr[i-1]) + arr[i];
		DP[i] = max(DP[i], DP[i-4] + arr[i-1] + arr[i]);
	}

	int _max=0;
	for(int i=1;i<=N;i++){
		// cout << "	DP[i] : " << DP[i] << "\n";
		_max = max(_max, DP[i]);
	}

	// int ans = max(DP[N][0], DP[N][1]);
	// cout << ans << "\n";
	cout << _max;
	
	return 0;
}



/*
00:51 Problem Analysis.
05:05 main() Completed.
11:04 _max 도입.
12:56 pause

14:22 2*N으로 변경시키기..
22:02 main() Completed.

25:16
DP[i][2] 2연속 개념 도입.



30:06 main() Completed.
DP[i] = max(DP[i], DP[i-3] + arr[i]); 
삽입
6
99 99 1 1 99 99

35:08
DP[i] = max(DP[i], DP[i-4] + arr[i-1] + arr[i]);
삽입

240810 35:08
*/
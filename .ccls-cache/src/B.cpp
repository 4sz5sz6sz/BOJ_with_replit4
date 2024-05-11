#define IDX_MAX 5001
#include<bits/stdc++.h>
using namespace std;

int A[IDX_MAX][IDX_MAX];
int DP[IDX_MAX][IDX_MAX];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vector<int> arr(N+1);
	for(int i=1;i<=N;i++){
		cin >> arr[i];
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(arr[i] <= arr[j])
				A[i][j] = 1;
		}
	}

	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(A[i][j])
				DP[i][j] = DP[i-1][j-1] + A[i][j];
		}
	}

	long long sum=0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			sum+=DP[i][j];
		}
	}

	cout << sum << "\n";
	
	return 0;
}



/*
51:29 Problem Analysis.
58:23 TC passed.
240511 58:29
*/
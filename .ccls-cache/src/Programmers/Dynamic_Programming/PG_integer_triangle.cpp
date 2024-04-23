#define IDX_MAX 501
#include <bits/stdc++.h>
using namespace std;

int dp[IDX_MAX][IDX_MAX];
int A[IDX_MAX][IDX_MAX];
int N;

int solution(vector<vector<int>> triangle) {
	N = triangle.size();

	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			A[i+1][j+1] = triangle[i][j];
		}
	}
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=i;j++){
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + A[i][j];
		}
	}

	int ret=0;
	for(int i=1;i<=N;i++){
		ret = max(ret,dp[N][i]);
	}
	return ret;
}

/*
01:27 Problem Analysis.
05:48 solution() Completed.
07:53 TC passed.
240422 
*/
#define MOD 1000000007
#define IDX_MAX 101
#include<bits/stdc++.h>
using namespace std;

int dp[IDX_MAX][IDX_MAX];
int board[IDX_MAX][IDX_MAX];
int N,M;


int solution(int m, int n, vector<vector<int>> puddles){
	N = n; M = m;
	dp[1][1] = 1;
	for(int i=0;i<puddles.size();i++){
		int nx = puddles[i][1];
		int ny = puddles[i][0];
		board[nx][ny] = 1;
	}
	for(int x=1;x<=N;x++){
		for(int y=1;y<=M;y++){
			if(x==1 && y==1) continue;	//initialize 1
			if(board[x][y]) continue;	//wall
			dp[x][y] = dp[x-1][y]%MOD + dp[x][y-1]%MOD;
			dp[x][y]%=MOD;
		}
	}
	
	//int ret;
	return dp[N][M];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	//int n,m;
	vector<vector<int>>puddles = {{2,2},{3,2}, {1,4}};	//1-indexed
	//cin >> n >> m;
	cout << solution(4,3,puddles);

	return 0;
}

/*
02:20 Problem Analysis.
06:59 solution() Completed.
10:19 TC passed.
WA...
12:54 MOD 추가.

21:12
int nx = puddles[i][0];
int ny = puddles[i][1];
에서
int nx = puddles[i][1];
int ny = puddles[i][0];
로 변경.

240423 10:29
*/
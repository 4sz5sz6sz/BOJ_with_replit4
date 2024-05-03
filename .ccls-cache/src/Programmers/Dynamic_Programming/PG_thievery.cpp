#define IDX_MAX 1000001
#include<bits/stdc++.h>
using namespace std;

int DP[IDX_MAX][2];
int A[IDX_MAX];
int N;

int solution(vector<int> money) {
	int answer = 0;

	N = money.size();
	for(int i=0;i<N;i++){
		A[i] = money[i];
	}

	int loop=2;

	//1회차 : 0번이 털릴 수도 있음.  -> "N-1은 무조건 안 털림"
	//2회차 : "0번이 무조건 안털림" -> N-1은 털릴 수도 있음.
	while(loop--){
		if(loop==1){
			DP[0][0] = 0;
			DP[0][1] = A[0];
		}
		else{
			DP[0][0] = 0;
			DP[0][1] = 0;
		}
		//DP[0][1] = 0;

		for(int i=1;i<N-1;i++){
			DP[i][0] = max(DP[i-1][0], DP[i-1][1]);
			DP[i][1] = DP[i-1][0] + A[i];
		}

		if(loop==1){
			DP[N-1][0] = max(DP[N-2][0], DP[N-2][1]);
			DP[N-1][1] = max(DP[N-2][0], DP[N-2][1]);
		}
		else{
			DP[N-1][0] = max(DP[N-2][0], DP[N-2][1]);
			DP[N-1][1] = DP[N-2][0] + A[N-1];
		}
		int cur = max(DP[N-1][0],DP[N-1][1]);
		answer = max(answer, cur);
	}

	return answer;
}

/*
12:21 Problem Analysis.
22:59 main() Completed.
25:55 TC passed.
240503 26:44
*/
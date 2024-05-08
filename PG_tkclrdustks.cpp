	#define INF 0x3f3f3f3f
	#define IDX_MAX 207
	#define MIN 0
	#define MAX 1
	#include<bits/stdc++.h>
	using namespace std;

	int A[IDX_MAX];
	char op[IDX_MAX];
	int DP[IDX_MAX][IDX_MAX][2];    //1-indexed

	int solution(vector<string> arr)
	{
		int answer = -1;
		int N = arr.size()/2+1;
		for(int i=0;i<arr.size();i++){
			if(i & 1)
				op[i/2+1] = arr[i][0]; //i/2+2 대신 i/2+1 넣음. mid 값으로 접근 가능.
			else
				A[i/2+1] = stoi(arr[i]);
		}
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				DP[i][j][MIN] = INF;
				DP[i][j][MAX] = -INF;
			}
		}

		for(int i=1;i<=N;i++){
			DP[i][i][MIN] = A[i];
			DP[i][i][MAX] = A[i];
			//cout << A[i];
		}

		for(int d=1;d<=N;d++){
			for(int i=1;i<=N;i++){
				int j = i+d;
				if(j > N) break;
				for(int k=i;k+1<=j;k++){
					if(op[k]=='+'){
						DP[i][j][MAX] = max(DP[i][j][MAX], DP[i][k][MAX] + DP[k+1][j][MAX]);
						DP[i][j][MIN] = min(DP[i][j][MIN], DP[i][k][MIN] + DP[k+1][j][MIN]);
					}
					else{
						DP[i][j][MAX] = max(DP[i][j][MAX], DP[i][k][MAX] - DP[k+1][j][MIN]);
						DP[i][j][MIN] = min(DP[i][j][MIN], DP[i][k][MIN] - DP[k+1][j][MAX]);
					}
					/*
					cout << "   i : " << i;
					cout << "   j : " << j;
					cout << "   k : " << k;
					cout << "   DP[i][j][MAX] : " << DP[i][j][MAX];
					cout << "   DP[i][j][MIN] : " << DP[i][j][MIN];
					cout << "\n";
					*/
				}
			}
		}

		return DP[1][N][MAX];
	}

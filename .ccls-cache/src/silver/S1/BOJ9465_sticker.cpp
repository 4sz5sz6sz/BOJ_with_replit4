#define IDX_MAX 100001
#include <bits/stdc++.h>
using namespace std;

int DP[2][IDX_MAX];
int A[2][IDX_MAX];
int N;

void Init();

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	while(T--){
		cin >> N;
		Init();
		for(int j=0;j<2;j++){
			for(int i=1;i<=N;i++){
				cin >> A[j][i];
			}
		}

		DP[0][1] = A[0][1];
		DP[1][1] = A[1][1];
		
		for(int i=1;i<=N;i++){
			DP[0][i] = max(DP[1][i-1], DP[1][i-2]) + A[0][i];
			DP[1][i] = max(DP[0][i-1], DP[0][i-2]) + A[1][i];
		}
		
		cout << max(DP[0][N], DP[1][N]) << "\n";
	}
	
	return 0;
}

void Init(){
	for(int j=0;j<2;j++){
		for(int i=1;i<=N;i++){
			DP[j][i] = 0;
		}
	}

	for(int j=0;j<2;j++){
		for(int i=1;i<=N;i++){
			A[j][i] = 0;
		}
	}
}

/*
04:47 Promblem Analysis.
09:10 main(), Init() Completed.
10:41 TC passed.
240418 10:45
*/